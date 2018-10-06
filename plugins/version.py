import colorsys
import functools
import math
import time

from _remote import ffi, lib
from manager import PluginBase
import util

VTEMPLATE = 'client v{0} + sbppf {1.VERSION}'


class Plugin(PluginBase):
    def onInit(self):
        self.vtxt = util.PlainText(size=16, font='HemiHeadBold')

    def afterUpdate(self):
        menu = self.refs.MainMenu
        if menu == ffi.NULL or menu.version == ffi.NULL:
            return
        menu.version.asUIElement.show = False
        if len(self.vtxt.text) == 0:
            sbver = ffi.string(menu.version.text.s).decode()
            self.vtxt.text = VTEMPLATE.format(sbver, self.refs)

    def onPresent(self):
        if self.refs.MainMenu == ffi.NULL:
            return
        t = time.perf_counter()
        # col = colorsys.hsv_to_rgb((t % 10) / 10, 0.7, 1)
        # col = functools.reduce(lambda c, x: (c << 8) + int(x * 255), col, 0)
        # self.vtxt.color = col
        self.vtxt.alpha = abs(math.sin(t * 2)) * 0.7 + 0.3
        self.vtxt.draw(4, self.refs.windowH - 4, anchorY=1)

    def __del__(self):
        menu = self.refs.MainMenu
        if menu != ffi.NULL and menu.version != ffi.NULL:
            menu.version.asUIElement.show = True
