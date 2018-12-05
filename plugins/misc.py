import colorsys
import logging
import time

from _remote import ffi, lib
from manager import PluginBase
import util

FLAGS = {
    'drawHUD': True,
    'drawTiles': True,
    'drawEdge': True,
    'drawScatter': True,
    'drawUniform': True,
    'drawHitBoxes': False,
    'drawBoxes': False
}

# a "big" number (sufficiently big, but below 2**24)
BN = 1000000


class Plugin(PluginBase):
    def onInit(self):
        # self.config.option('menu_bg', 0xff1d264d, 'color')
        self.config.option('centered', 1, 'int')
        self.config.option('max_bg_value', 1, 'float')
        self.config.option('hide_cursor_after', 1, 'float')
        self.config.options('bool', FLAGS)

        self.config.option('fixed_window', False, 'bool')
        self.config.options('int', {
            'window_x': 0,
            'window_y': 0,
            'window_width': 1920,
            'window_height': 1080
        })

        nd = lib.SDL_GetNumVideoDisplays()
        if nd > 1:
            logging.info('displays:')
            rect = ffi.new('struct SDL_Rect *')
            for i in range(nd):
                res = lib.SDL_GetDisplayBounds(i, rect)
                if res != 0:
                    logging.warning(lib.SDL_GetError())
                    continue
                logging.info('  {1}: {0.w}x{0.h} at ({0.x},{0.y})'.format(rect, i))

        self.positioned = False

    def afterUpdate(self):
        for f in FLAGS:
            self.refs[f][0] = getattr(self.config, f)

        tdt = self.config.hide_cursor_after
        if tdt > 0:
            dt = time.perf_counter() - self.refs.lastMove
            visible = lib.SDL_ShowCursor(-1)
            if dt > tdt and visible == 1:
                lib.SDL_ShowCursor(0)
            if dt <= tdt and visible == 0:
                lib.SDL_ShowCursor(1)

        menu = self.refs.MainMenu
        if menu != ffi.NULL:
            # cancel logo flash animation
            if menu.logo != ffi.NULL and menu.logo.anim != 0:
                menu.logo.anim = 0

        gc = self.refs.GameClient
        if gc == ffi.NULL:
            return

        # disable autokick
        gc.sinceKeypress = 0

        # reduce background brightness if needed
        if self.config.max_bg_value < 1:
            bg = self.refs.stage[0].backgroundColor
            r, g, b = ((bg >> 16) & 0xff, (bg >> 8) & 0xff, bg & 0xff)
            h, s, v = colorsys.rgb_to_hsv(r / 255, g / 255, b / 255)
            if v > self.config.max_bg_value:
                v = self.config.max_bg_value
                r, g, b = colorsys.hsv_to_rgb(h, s, v)
                bg = ((int(r * 255) & 0xff) << 16) +\
                    ((int(g * 255) & 0xff) << 8) +\
                    (int(b * 255) & 0xff)
                self.refs.stage[0].backgroundColor = bg | 0xff000000

        wv = self.refs.WorldView

        if wv == ffi.NULL:
            self._shake = 0
            self._flash = 0
            return

        if self.config.centered == 1:
            # centered camera (old style)
            wv.offsetsInitialized = False
        elif self.config.centered == 2:
            # centered, allow camera outside world bounds
            wv.offsetsInitialized = False
            if wv.playerBounds.w < wv.worldBounds.w + BN:
                wv.playerBounds.x -= BN
                wv.playerBounds.y -= BN
                wv.playerBounds.w += BN * 2
                wv.playerBounds.h += BN * 2

        # set playerBounds back to previous values if switched from mode 2
        if self.config.centered != 2 and wv.playerBounds.w > wv.worldBounds.w + BN:
            wv.playerBounds.x += BN
            wv.playerBounds.y += BN
            wv.playerBounds.w -= BN * 2
            wv.playerBounds.h -= BN * 2
            wv.offsetsInitialized = False

    def onPresent(self):
        self.reposition_window()

    def reposition_window(self):
        if self.config.fixed_window is False or self.positioned:
            return

        window = self.refs.window_[0]

        # get current state
        flags = lib.SDL_GetWindowFlags(window)
        # exit fullscreen if enabled
        if flags & 1 > 0:
            lib.SDL_SetWindowFullscreen(window, 0)

        WW = self.config.window_width
        WH = self.config.window_height

        # force size
        # SetWindowResizable does not exist in game's version of SDL :/
        lib.SDL_SetWindowMinimumSize(window, WW, WH)
        lib.SDL_SetWindowMaximumSize(window, WW, WH)

        # "borderless"
        lib.SDL_SetWindowBordered(window, 0)

        # lib.SDL_SetWindowSize(window, WW, WH)
        lib.SDL_SetWindowPosition(
            window, self.config.window_x, self.config.window_y)

        self.positioned = True
