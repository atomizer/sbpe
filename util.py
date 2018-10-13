import logging
import math

from PIL import Image

from _remote import ffi, lib

refs = None
STRUCTTYPES = ffi.list_types()[1]

GLFUNCTIONS = '''
glGetError glEnable glDisable glHint
glTexImage2D glTexParameteri
'''.split()

GL_TEXTURE_2D = 0x0DE1

GL_TEXTURE_BASE_LEVEL = 0x813C
GL_TEXTURE_MAX_LEVEL = 0x813D

GL_TEXTURE_MAG_FILTER = 0x2800
GL_TEXTURE_MIN_FILTER = 0x2801

GL_NEAREST_MIPMAP_NEAREST = 0x2700
GL_NEAREST_MIPMAP_LINEAR = 0x2702
GL_LINEAR_MIPMAP_NEAREST = 0x2701
GL_LINEAR_MIPMAP_LINEAR = 0x2703

GL_UNSIGNED_BYTE = 0x1401
GL_RGBA = 0x1908


# classes ####################################################################

class PlainText(object):
    '''wrapper for text drawing'''
    def __init__(self, *, size=14, outlineSize=2, font=b'TenbyFive',
                 color=0xffffff, outlineColor=0x000000, alpha=1.0,
                 screenCoords=True):
        self.size = size
        self.outlineSize = outlineSize
        self.font = font
        self.color = color
        self.outlineColor = outlineColor
        self._texture = 0
        self.text = b''
        self._w = ffi.new('int *')
        self._h = ffi.new('int *')
        self.w = self.h = 0
        self.alpha = alpha
        self._dirty = False
        self.screenCoords = screenCoords

    def __setattr__(self, name, val):
        if name == 'size' or name == 'outlineSize':
            val = int(val)
        elif name == 'color' or name == 'outlineColor':
            val = (int(val) & 0xffffff) | 0xff000000
        elif name == 'font' or name == 'text':
            if type(val) != bytes:
                if type(val) == str:
                    val = val.encode('utf-8')
                else:
                    raise AttributeError(
                        '"{}" must be str or bytes, got {}'.format(
                            name, str(type(val))))
        else:  # anything else is not affecting texture - pass through
            if name == 'alpha':
                val = max(0, min(1, val))
                self._cmod = (math.floor(val * 255) << 24) & 0xff000000
            object.__setattr__(self, name, val)
            return

        # check if the texture needs updating
        try:
            oldval = self.__getattribute__(name)
            if oldval != val:
                self._dirty = True
        except AttributeError:
            pass
        object.__setattr__(self, name, val)

    def updateTexture(self):
        self._texture = refs.XDL_CreateTextTexture(
            self._texture, self.font, self.size, self.color,
            self.text, self.outlineSize, self.outlineColor)
        refs.XDL_QueryTexture(self._texture, self._w, self._h)
        self.w = self._w[0]
        self.h = self._h[0]

    def __del__(self):
        if self._texture > 0:
            refs.XDL_DestroyTexture(self._texture)

    def draw(self, x, y, anchorX=0, anchorY=0, angle=0):
        if self.size <= 0 or len(self.text) == 0:
            return
        if self._dirty:
            self.updateTexture()
            self._dirty = False
        if self._texture <= 0:
            return

        w = ws = self.w
        h = hs = self.h

        if self.screenCoords:
            ws *= refs.scaleX
            hs *= refs.scaleY
            x *= refs.scaleX
            y *= refs.scaleY

        x -= anchorX * ws
        y -= anchorY * hs
        rotDegt = round(angle * 10)

        refs.XDL_DrawTexture(
            self._texture, 0, 0, w, h,
            round(x), round(y), round(ws), round(hs),
            rotDegt, w // 2, h // 2,
            0, self._cmod, lib.BLENDMODE_BLEND)


class MultilineText(object):
    def __init__(self, *, spacing=15, **kwargs):
        self._kwargs = kwargs
        self.spacing = spacing
        self.children = []

    def __setattr__(self, name, val):
        if name == '_kwargs' or name == 'children':
            pass
        elif name == 'spacing':
            val = int(val)
            if val < 0:
                val = 0
        elif name == 'text':
            lines = val.splitlines()
            if len(self.children) < len(lines):
                for i in range(len(lines) - len(self.children)):
                    self.children.append(PlainText(**self._kwargs))
            for i in range(len(lines)):
                self.children[i].text = lines[i]
            self.children = self.children[:len(lines)]
        else:
            self._kwargs[name] = val
            for t in self.children:
                t.__setattr__(name, val)

        object.__setattr__(self, name, val)

    def draw(self, x, y):
        for t in self.children:
            t.draw(x, y)
            y += self.spacing


class NumberDict(PlainText):
    def __init__(self, *, size=16, outlineSize=2, font=b'HemiHeadBold',
                 color=0xffffff, outlineColor=0x000000, screenCoords=False):
        super().__init__(
            size=size, outlineSize=outlineSize, font=font,
            color=color, outlineColor=outlineColor, screenCoords=screenCoords)

    def updateTexture(self):
        self._texture = refs.XDL_GetNumberDict(
            self.font, self.size, self.color,
            self.outlineSize, self.outlineColor)
        refs.XDL_QueryTexture(self._texture, self._w, self._h)
        self.w = self._w[0]
        self.h = self._h[0]

    def draw(self, num, x, y, anchorX=0, anchorY=0):
        if self.size <= 0:
            return
        if self._dirty:
            self.updateTexture()
            self._dirty = False
        if self._texture <= 0:
            return

        _nw = ffi.new('int *')
        _nh = ffi.new('int *')
        refs.XDL_SizeFromNumberDict(self._texture, num, _nw, _nh)
        nw = _nw[0]
        nh = _nh[0]
        sw = nw * refs.scaleX
        sh = nh * refs.scaleY

        if self.screenCoords:
            x *= refs.scaleX
            y *= refs.scaleY

        x -= anchorX * sw
        y -= anchorY * sh

        refs.XDL_DrawFromNumberDict(
            self._texture, num, round(nw), round(nh),
            round(x), round(y), round(sw), round(sh))

    def __del__(self):
        pass


# functions ##################################################################

def loadGLFunctions():
    for name in GLFUNCTIONS:
        refs[name] = ffi.cast(
            'p' + name, lib.SDL_GL_GetProcAddress(bytes(name, 'utf-8')))


def loadMipmaps(pname, sheet):
    if GLFUNCTIONS[0] not in refs:
        loadGLFunctions()

    maxlevel = refs.config.getint('general', 'mipmap_maxlevel', fallback=0)
    if maxlevel < 1:
        return

    for level in range(1, maxlevel + 1):
        fname = 'data/texture/{}.m{}.{}.png'.format(pname, level, sheet)
        try:
            img = Image.open(fname)
        except IOError:
            logging.error('could not load: "{}"'.format(fname))
            return
        pixels = ffi.from_buffer(img.tobytes())
        refs.glTexImage2D(
            GL_TEXTURE_2D, level, 4, img.width, img.height,
            0, GL_RGBA, GL_UNSIGNED_BYTE, pixels)

        logging.debug('pack {} sheet {} level {} err {}'.format(
            pname, sheet, level, refs.glGetError()))

    refs.glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, maxlevel)
    refs.glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                         GL_LINEAR_MIPMAP_LINEAR)


def updateState():
    '''make commonly used data more accessible to plugins'''
    if GLFUNCTIONS[0] not in refs:
        loadGLFunctions()

    if refs.stage[0] == ffi.NULL:
        return

    # top level children of stage
    tops = []
    types = []
    for t in vec2list(refs.stage[0].asUIElementContainer.children):
        clname = getClassName(t)
        types.append(clname)
        if clname in STRUCTTYPES:
            t = ffi.cast('struct {} *'.format(clname), t)
        tops.append(t)
    refs.tops = tops
    refs.topTypes = types

    # main menu
    if types[0] == 'MainMenu':
        refs.MainMenu = tops[0]
    else:
        refs.MainMenu = ffi.NULL

    # game client
    refs.GameClient = refs.WorldClient = refs.ClientWorld =\
        refs.WorldView = ffi.NULL

    if types[0] == 'GameClient':
        refs.GameClient = tops[0]
        refs.WorldClient = refs.GameClient.worldClient
        if refs.WorldClient != ffi.NULL:
            refs.WorldView = refs.WorldClient.worldView
            refs.ClientWorld = refs.WorldClient.clientWorld
            if refs.ClientWorld == ffi.NULL or refs.WorldView == ffi.NULL:
                refs.ClientWorld = refs.WorldView = ffi.NULL

    # window size and scale
    ww_ = ffi.new('int *')
    wh_ = ffi.new('int *')
    lib.SDL_GetWindowSize(refs.window_[0], ww_, wh_)
    ww = ww_[0] or 1  # avoid potential division by zero
    wh = wh_[0] or 1
    refs.windowW = ww
    refs.windowH = wh
    refs.scaleX = refs.canvasW_[0] / ww
    refs.scaleY = refs.canvasH_[0] / wh

    # add more useful things here


def getstr(stdstring):
    if stdstring == ffi.NULL:
        return '(NULL)'
    return ffi.string(stdstring.s, 1000).decode('utf-8', errors='replace')


def veclen(vector, itemtype='void*'):
    if vector.start == ffi.NULL or vector.finish == ffi.NULL:
        return 0
    return (vector.finish - vector.start) // ffi.sizeof(itemtype)


def vec2list(vector, itemtype='void*'):
    '''std::vector -> list'''
    if vector.start == ffi.NULL or vector.finish == ffi.NULL or\
            vector.endOfStorage <= vector.start:
        return []
    n = (vector.finish - vector.start) // ffi.sizeof(itemtype)
    return ffi.unpack(ffi.cast(itemtype + '*', vector.start), n)


def sVecMap2list(svecmap, itemtype='void*'):
    '''struct SortedVecMap -> list'''
    lst = vec2list(svecmap.vec, 'struct SortedVecElement')
    for i in range(len(lst)):
        lst[i] = ffi.cast(itemtype, lst[i].obj)
    return lst


def worldobjects(subworld):
    '''get objects from a member of subclass of SubWorldImpl as a list'''
    if subworld == ffi.NULL:
        return []
    return sVecMap2list(subworld.asSubWorldImpl.objs, 'struct WorldObject *')


def getClassName(obj):
    '''
    class name of a C++ object (assuming gcc memory layout).
    doesn't demangle complicated names
    '''
    if obj == ffi.NULL:
        return 'NULL'
    classptr = ffi.cast('void**', obj)[0]
    # vtable (1 up) -> type -> name (1 down)
    nameptr = ffi.cast('void***', classptr - 4)[0][1]
    cname = ffi.string(ffi.cast('char*', nameptr), 100)
    return cname[1 if len(cname) < 11 else 2:].decode()


def getUITree(obj, depth=0):
    '''printable UI element tree starting from obj'''
    if obj == ffi.NULL:
        return ' ' * depth + 'NULL'
    cname = getClassName(obj)
    uiel = ffi.cast('struct UIElement*', obj)
    res = ' ' * depth + '{0} ({1.x}, {1.y}) {1.w}x{1.h}'.format(cname, uiel)
    if cname in refs.CASTABLE['UIElementContainer']:
        uiec = ffi.cast('struct UIElementContainer*', obj)
        for elem in vec2list(uiec.children):
            res += '\n' + getUITree(elem, depth + 2)
    return res
