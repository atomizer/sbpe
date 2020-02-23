import argparse
import array
import concurrent.futures
import io
import logging
import math
import os
import random
import time

# installed
from PIL import Image, ImageDraw

# generated
import bpb_pb2

# own
import rectbinpack

BASEPATH = os.path.abspath('../data')
OUTDIR = 'out'


def readFile(name):
    try:
        with open(name, 'rb') as f:
            s = f.read()
        return s
    except OSError:
        logging.error('could not read: {}'.format(name))
        # todo: handle
        raise


def getFileTime(name):
    try:
        return os.path.getmtime(name)
    except OSError:
        return 0


def readDataVersion(name=None):
    if name is None:
        name = os.path.join(BASEPATH, 'dataVersion.bpb')
    return bpb_pb2.DataVersion.FromString(readFile(name))


def readDesc(src):
    rawdesc = bpb_pb2.ImageFileDescription.FromString(src)
    res = {'raw': rawdesc}

    uiids = []
    i = 0
    for sheet in rawdesc.sheetDef:
        for img in sheet.imageDef:
            uiids.append((img, i))
        i += 1
    res['uiids'] = uiids

    return res


def loadSheets(sheetnames):
    sheets = {}
    for name in sheetnames:
        b = io.BytesIO(readFile(name))
        sheets[int(name.split('.')[1])] = Image.open(b)
    return sheets


def loadSprites(uiids, sheets):
    def sprite(u):
        idef = u[0]
        box = (idef.x, idef.y, idef.x + idef.w, idef.y + idef.h)
        return sheets[u[1]].crop(box)

    sprites = list(map(sprite, uiids))
    return sprites


def repack(items, size):
    res = rectbinpack.MaxRects(size[0], size[1], items)

    # occ = ', '.join(['{:.3f}'.format(x) for x in res['occupancy']])
    # logging.info('packed coverage: ' + occ)
    if len(items) > 0:
        logging.error('failed to pack {} sprites!'.format(len(items)))

    return res['bins']


def extendSprite(spr, border, scale, tbox=None):
    basic = False
    if tbox is None:
        tbox = (0, 0, spr.width, spr.height, 0, 0)
        basic = True

    bx, by, bw, bh, ox, oy = tbox
    osw = math.ceil((spr.width + ox) / scale)
    osh = math.ceil((spr.height + oy) / scale)
    obw = math.ceil(bw / scale)
    obh = math.ceil(bh / scale)

    # source for border extensions
    if basic:
        bsrc = spr
    else:
        bsrc = spr.crop((bx, by, bx + bw, by + bh))

    # apply offset before scaling
    if not basic:
        spr = spr.crop((-ox, -oy, spr.width, spr.height))

    if scale > 1:
        spr = spr.resize((osw, osh), Image.LANCZOS)
        if basic:
            bsrc = spr
        else:
            bsrc = bsrc.resize((obw, obh), Image.LANCZOS)

    bx = (bx + ox) // scale + border
    by = (by + oy) // scale + border

    r = Image.new('RGBA', (border * 2 + spr.width, border * 2 + spr.height))

    # extend the sprite by 1 pixel in all directions
    r.paste(bsrc.crop((0, 0, obw, 1)), (bx, by - 1))
    r.paste(bsrc.crop((0, 0, 1, obh)), (bx - 1, by))
    r.paste(bsrc.crop((0, obh - 1, obw, obh)), (bx, by + obh))
    r.paste(bsrc.crop((obw - 1, 0, obw, obh)), (bx + obw, by))
    # corners
    r.paste(bsrc.crop((0, 0, 1, 1)), (bx - 1, by - 1))
    r.paste(bsrc.crop((obw - 1, 0, obw, 1)), (bx + obw, by - 1))
    r.paste(bsrc.crop((0, obh - 1, 1, obh)), (bx - 1, by + obh))
    r.paste(bsrc.crop((obw - 1, obh - 1, obw, obh)), (bx + obw, by + obh))

    if basic:
        r.paste(spr, (border, border))
    else:
        # allow opaque external pixels (intentional overflow) to
        # overwrite extended borders, better preserving original art
        r.alpha_composite(spr, (border, border))
        # ...but overwrite transparency that could leak in from the edges
        r.paste(bsrc, (bx, by))

    if False and border > 1:
        draw = ImageDraw.Draw(r)
        color = 'hsv({},100%,100%)'.format(random.randrange(360))
        draw.rectangle([0, 0, r.width - 1, r.height - 1], outline=color)

    return r


def makeSheet(size, sprites, coords, level, maxlevel, tboxes):
    border = 1 << (maxlevel - level)
    scale = 1 << level

    im = Image.new('RGBA', (size[0] // scale, size[1] // scale))

    for r in coords:
        spr = sprites[r[2]]

        if r[2] in tboxes:
            tbox = tboxes[r[2]]
        else:
            tbox = None

        spr = extendSprite(spr, border, scale, tbox)
        im.paste(spr, (r[0] // scale, r[1] // scale))

    return im


def doPack(params):
    name, bpbname, sheetnames, mipmaps = params

    logging.basicConfig(level=logging.INFO)
    logging.getLogger().handlers[0].setFormatter(
        logging.Formatter('[%(levelname)s] ({}) %(message)s'.format(name)))

    desc = readDesc(readFile(bpbname))
    uiids = desc['uiids']
    pb = desc['raw']

    # phase 1 - sprites

    sheets = loadSheets(sheetnames)
    sheetsize = sheets[0].size

    border = 1 << mipmaps

    # "edge" rectangle of a tile sprite does not necessarily match
    # the sprite's bounding box
    tboxes = {}
    for td in pb.tileDesc:
        idef = uiids[td.uiid][0]
        bx = idef.rpX - td.tw * 16
        by = idef.rpY - td.th * 16

        # offset tile sprites so that the tile edges match
        # pixel edges at the lowest mipmap level.
        offx = (border - (bx % border)) % border
        offy = (border - (by % border)) % border

        tboxes[td.uiid] = (bx, by, td.tw * 32, td.th * 32, offx, offy)

    items = {}
    for i, u in enumerate(uiids):
        elw = u[0].w
        elh = u[0].h

        if i in tboxes:
            elw += tboxes[i][4]
            elh += tboxes[i][5]

        elw = math.ceil(elw / border) * border + border * 2
        elh = math.ceil(elh / border) * border + border * 2

        if elw > sheetsize[0] or elh > sheetsize[1]:
            logging.warning('sprite {} was clipped to fit: {} > {}'.format(
                i, (elw, elh), sheetsize))
            elw = min(sheetsize[0], elw)
            elh = min(sheetsize[1], elh)

        items[i] = (elw, elh)

    packed = repack(items, sheetsize)

    sprites = loadSprites(uiids, sheets)
    logging.info('{} sprites'.format(len(sprites)))

    logging.info('writing png...')

    for i in range(len(packed)):
        for level in range(mipmaps + 1):
            s = makeSheet(sheetsize, sprites, packed[i], level, mipmaps, tboxes)

            fname = '{}.m{}.{}.png'.format(name, level, i)
            logging.info(fname)
            try:
                s.save(fname)
            except OSError:
                logging.error('failed to save {}!'.format(fname))

    # phase 2 - bpb

    logging.info('writing bpb...')

    oldDefs = []
    for sheet in pb.sheetDef:
        oldDefs = oldDefs + sheet.imageDef[:]

    # overwrite sprite coords and remember the old -> new uiid mapping
    del pb.sheetDef[:]
    newsheets = []
    umap = {}
    umap[-1] = -1
    i = 0
    for coords in packed:
        sheet = bpb_pb2.SheetDefinition()

        for c in coords:
            o = oldDefs[c[2]]

            nx = c[0] + border
            ny = c[1] + border

            # add tile sprite alignment offsets
            if c[2] in tboxes:
                tb = tboxes[c[2]]
                nx += tb[4]
                ny += tb[5]

            sheet.imageDef.add(x=nx, y=ny, w=o.w, h=o.h, rpX=o.rpX, rpY=o.rpY)
            umap[c[2]] = i
            i += 1
        newsheets.append(sheet)

    pb.sheetDef.extend(newsheets)

    # fix uiids

    # ImageVidDescription
    for el in pb.imageVidDesc:
        el.uiid = umap[el.uiid]

    # TileDescription
    for el in pb.tileDesc:
        el.uiid = umap[el.uiid]

    # AnimatedImageDescription
    for ai in pb.animatedImageDesc:
        for imd in ai.imageMapDesc:
            for imdm in imd.mapping:
                imdm.uiid = umap[imdm.uiid]
                imdm.targetUIID = umap[imdm.targetUIID]
        for ad in ai.animDesc:
            for fd in ad.frameDesc:
                for fde in fd.element:
                    fde.uiid = umap[fde.uiid]

    # write file

    descname = '{}.m.bpb'.format(name)
    try:
        with open(descname, 'wb') as f:
            f.write(pb.SerializeToString())
    except OSError:
        logging.error('failed to save {}!'.format(descname))

    return len(packed)


def isComplete(name, nsheets, mipmaps, mtime):
    if nsheets == 0:
        return False

    mbpb = '{}.m.bpb'.format(name)

    # enumerate all expected files
    targets = [mbpb]
    for level in range(mipmaps + 1):
        for sheet in range(nsheets):
            targets.append('{}.m{}.{}.png'.format(name, level, sheet))

    # if any of the files are old or missing, return False
    return all(getFileTime(tfile) > mtime for tfile in targets)


def main(outdir, mipmaps):
    if not os.path.isdir(outdir):
        os.mkdir(outdir)
    os.chdir(outdir)

    dv = readDataVersion()

    plens = {}
    if os.path.exists('dataVersion.m.bpb'):
        ndv = readDataVersion('dataVersion.m.bpb')
        for pack in ndv.pvid:
            plens[pack.name] = len(pack.imageIds)

    jobs = {}

    for pack in dv.pvid:
        # enumerate all the original file names based on dataVersion
        bpbname = '{0}.{1}.bpb'.format(pack.name, pack.descId)
        bpbname = os.path.join(BASEPATH, bpbname)
        sheetnames = []
        for img in pack.imageIds:
            sname = '{0}.{1}.png'.format(pack.name, img)
            sheetnames.append(os.path.join(BASEPATH, sname))

        # most recent modified time of originals
        lastmtime = max(getFileTime(name) for name in (bpbname, *sheetnames))

        plen = 0
        if pack.name in plens:
            plen = plens[pack.name]

        if isComplete(pack.name, plen, mipmaps, lastmtime):
            logging.debug('ok: {}'.format(pack.name))
        else:
            jobs[pack.name] = (pack.name, bpbname, sheetnames, mipmaps)

    if len(jobs) > 0:
        fnames = {}

        # run packs in parallel
        logging.info('please wait, updating: {}...'.format(
            ', '.join(jobs.keys())))

        executor = concurrent.futures.ProcessPoolExecutor(
            max_workers=min(len(jobs), os.cpu_count() or 1))

        for pname in jobs:
            future = executor.submit(doPack, jobs[pname])
            fnames[future] = pname

        # wait for everything to finish
        for future in concurrent.futures.as_completed(fnames):
            pname = fnames[future]
            plens[pname] = future.result()
            logging.info('done: {}'.format(pname))

        executor.shutdown()
    else:
        logging.info('all mipmaps are up to date')

    # modify dataVersion and write out dataVersion.m.bpb
    for pack in dv.pvid:
        pack.descId = 'm'
        del pack.imageIds[:]
        pack.imageIds.extend([
            'm0.{}'.format(i) for i in range(plens[pack.name])
        ])

    with open('dataVersion.m.bpb', 'wb') as f:
        f.write(dv.SerializeToString())


if __name__ == '__main__':
    logging.basicConfig(
        level=logging.INFO, format='[%(levelname)s] %(message)s')

    parser = argparse.ArgumentParser()
    # parser.add_argument('--name', default='all')
    parser.add_argument('-m', '--mipmaps', default=2, type=int)
    args = parser.parse_args()

    t = time.perf_counter()

    main(OUTDIR, args.mipmaps)

    logging.info('time: {:.2f}s'.format(time.perf_counter() - t))
