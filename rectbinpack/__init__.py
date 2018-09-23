from ._rbp import ffi, lib


def MaxRects(width, height, items, flip=False):
    def _pack():
        lib.MaxRects_init(width, height, flip)
        res = []

        n = len(items)
        sz = ffi.new('struct RectSize[]', n)
        i = 0
        for k in items:
            sz[i].width = items[k][0]
            sz[i].height = items[k][1]
            sz[i].id = k
            i += 1

        out = ffi.new('struct Rect**')
        outn = lib.MaxRects_insert(sz, n, lib.MaxRectsBestShortSideFit, out)
        rects = ffi.unpack(out[0], outn)

        for i in range(outn):
            r = rects[i]
            del items[r.id]
            res.append((r.x, r.y, r.id))

        return res

    occupancy = []
    bins = []

    while len(items) > 0:
        newbin = _pack()
        if len(newbin) == 0:
            break
        bins.append(newbin)
        occupancy.append(lib.MaxRects_occupancy())

    return dict(bins=bins, occupancy=occupancy)
