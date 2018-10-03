import configparser
import io
import json
import os
import platform
import subprocess
import time

from mayhem.proc import ProcessError
from mayhem.proc.native import NativeProcess

import logging
logging.basicConfig(level=logging.INFO, format='[%(levelname)s] %(message)s')

BASE = 0x400000
DEFAULTGAMEPATH = 'c:\\Program Files (x86)\\Steam\\SteamApps\\common\\StarBreak\\mvmmoclient.exe'

SCRIPTPATH = os.path.dirname(__file__) or os.getcwd()
REMOTEPATH = os.path.normpath(os.path.join(SCRIPTPATH, 'build/remote.bin'))
SYMQPATH = 'symquery/{}/bin/symquery'.format(platform.system())
SYMQPATH = os.path.normpath(os.path.join(SCRIPTPATH, SYMQPATH))
CONFFILE = os.path.join(SCRIPTPATH, 'config.ini')

STARTUP_OFFSET = subprocess.check_output([
    SYMQPATH, '-e', REMOTEPATH, '-s', 'kickstart'])
STARTUP_OFFSET = int(STARTUP_OFFSET.strip(), 16)

# offsets of these symbols will be passed to the remote
SYMLIST = '''
stage window_ canvasW_ canvasH_
mouseMoveCallback mouseButtonCallback windowEventCallback
userData_

XDL_GetWindowSize
XDL_DoEvents XDL_Clear XDL_Present
XDL_DrawPoint XDL_DrawLine XDL_DrawRect XDL_DrawTri XDL_FillRect XDL_FillTri
XDL_LoadTextFile XDL_LoadTextureFile XDL_CreateTextTexture
XDL_CalculateTextWidth XDL_LineSpacing
XDL_QueryTexture XDL_DrawTexture
XDL_GetNumberDict XDL_DrawFromNumberDict XDL_SizeFromNumberDict
XDL_DestroyTexture
XDL_TrackGAEvent

flags::drawHUD
flags::drawTiles
flags::drawEdge
flags::drawScatter
flags::drawUniform
flags::drawHitBoxes
flags::drawBoxes
'''.split()


def resolveSymbols(exepath):
    offsets = {}
    lines = subprocess.check_output([SYMQPATH, '-e', exepath, '--list'])
    lines = lines.decode().splitlines()
    for line in lines:
        line = line.split()
        if line[0] not in SYMLIST:
            continue
        sname = line[0]
        SYMLIST.remove(sname)
        off = line[1].split('-')[0]
        try:
            off = BASE + int(off, 16)
        except ValueError:
            logging.error('invalid offset "{0}" for "{1}"'.format(off, sname))
            return None
        offsets[sname] = off

    if len(SYMLIST) > 0:
        logging.error('could not find symbols: ' + ' '.join(SYMLIST))
        return None

    # with io.open('symbols.json', 'w') as f:
    #     json.dump(offsets, f, sort_keys=True, indent=2)
    return offsets


def inject(proc, data):
    payload = json.dumps(data).encode('utf-8') + b'\x00'
    try:
        lib_h = proc.load_library(REMOTEPATH)
        # write data to remote memory
        pmem = proc.allocate(size=len(payload))
        proc.write_memory(pmem, payload)
        # start remote thread
        addr = lib_h + STARTUP_OFFSET
        thr = proc.start_thread(addr, pmem)
        logging.info('starting from 0x{:x}'.format(addr))
        proc.join_thread(thr)
        logging.info('startup done')
        proc.free(pmem)
    except ProcessError as error:
        logging.error(error.msg)
        return False
    return proc


def runLoader(exepath=''):
    mipmaps = False
    if os.path.exists(CONFFILE):
        conf = configparser.ConfigParser()
        conf.read(CONFFILE)
        exepath = conf.get('general', 'game', fallback=exepath)
        mipmaps = conf.getboolean('general', 'mipmaps', fallback=False)

    if not os.path.isfile(exepath):
        logging.error('put the path to the game executable in ' + CONFFILE)
        return

    if mipmaps:
        gdir = os.path.dirname(os.path.abspath(exepath))
        tdir = os.path.join(gdir, 'data', 'texture')
        dvpath = os.path.join(tdir, 'dataVersion.bpb')
        dvmpath = os.path.join(tdir, 'dataVersion.m.bpb')
        dvbak = os.path.join(tdir, 'dataVersion.bpb.bak')

        if not os.path.exists(dvbak):
            # presumably there are no other instances running
            if not os.path.exists(dvmpath):
                logging.info('mipmaps enabled, but not found. generating...')

                import genmipmaps
                genmipmaps.BASEPATH = tdir
                mn = conf.getint('general', 'mipmap_maxlevel', fallback=2)
                genmipmaps.main(tdir, mipmaps=mn)

            os.rename(dvpath, os.path.join(tdir, 'dataVersion.bpb.bak'))
            os.rename(dvmpath, dvpath)

    gpop = subprocess.Popen([exepath], stderr=subprocess.PIPE,
                            cwd=os.path.dirname(exepath))
    try:
        proc = NativeProcess(pid=gpop.pid)
    except Exception:
        gpop.kill()
        raise

    logging.info('game pid {}'.format(proc.pid))

    data = {'path': SCRIPTPATH}

    offsets = resolveSymbols(exepath)
    if offsets is not None:
        data['offsets'] = offsets
        logging.info('symbols ok')
    else:
        logging.error('symbols not ok')
        gpop.kill()
        return False

    if not inject(proc, data):
        logging.error('injection not ok')
        gpop.kill()
        return False
    else:
        stderr = gpop.communicate()[1]
        logging.info('game closed: code {}'.format(gpop.returncode))
        if len(stderr) > 0:
            print(stderr.decode())

        if mipmaps and os.path.exists(dvbak):
            os.rename(dvpath, dvmpath)
            os.rename(dvbak, dvpath)

        return True


if __name__ == '__main__':
    logging.info('sbppf loader')
    runLoader(DEFAULTGAMEPATH)
