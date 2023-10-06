import time
import array

from _remote import ffi, lib
from manager import PluginBase
import util


class Plugin(PluginBase):
    def onInit(self):
        self.config.options('float', {'update': 0.2, 'average': 1})
        self.config.option('size', 16, 'int')
        self.config.option('color', 0xffffff00, 'color')
        self.config.option('res_size', 12, 'int')
        self.config.option('res_color', 0xffffffff, 'color')
        self.config.option('res_warning', 0xffff0000, 'color')
        self.config.option('buf_color', 0xffffffff, 'color')
        self.config.option('buf_size', 12, 'int')

        self.times = array.array('d')
        self.lastupd = self.prevt = time.perf_counter()
        self.txt = util.PlainText(font='HemiHeadBold')
        self.res = util.PlainText(font='HemiHeadBold')
        self.buf = util.PlainText(font='HemiHeadBold')
        self._oldres = 0

    def onPresent(self):
        t = time.perf_counter()
        self.times.append(t - self.prevt)
        self.prevt = t

        if t >= self.lastupd + self.config.update:
            self.lastupd = t

            s = n = 0
            for i in range(len(self.times) - 1, -1, -1):
                s += self.times[i]
                n += 1
                if s >= self.config.average:
                    break

            if i > 0:
                self.times = self.times[i:]

            if s == 0 or n == 0:
                return

            fps = n / s
            avgms = 1000 * s / n
            self.txt.text = '{:.1f}'.format(fps)

        self.txt.size = self.config.size
        self.txt.color = self.config.color
        self.txt.draw(self.refs.windowW - 4, 0, anchorX=1)

        cw = self.refs.ClientWorld
        if cw == ffi.NULL:
            self._oldres = 0
            return

        res = cw.timeReserve

        self.res.text = 'r:{}'.format(res)
        self.res.size = self.config.res_size

        if res < 900 and self._oldres >= res:
            self.res.color = self.config.res_warning
        else:
            self.res.color = self.config.res_color

        self.res.draw(self.refs.windowW - 4, self.txt.h, anchorX=1)
        self._oldres = res
        
        bufsum =  self.refs.GameClient.clientStats.bufSize.sum
        maxval = self.refs.GameClient.clientStats.bufSize.maxValues
        buf = int(bufsum/maxval)
        self.buf.text = 'buf:{}'.format(buf)
        self.buf.size = self.config.buf_size
        self.buf.color = self.config.buf_color
        self.buf.draw(self.refs.windowW - 4, self.res.h*2, anchorX=1)
