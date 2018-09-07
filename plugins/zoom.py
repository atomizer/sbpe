import time

from _remote import ffi, lib
from manager import PluginBase


def ease(start, end, stime, ctime, dur):
    t = ctime - stime
    if t > dur:
        return end
    if t < 0:
        return start
    t = t / dur
    pt = t * (2 - t)
    return round(start + (end - start) * pt)


class Plugin(PluginBase):
    def onInit(self):
        self.config.option('active', False, 'bool')
        self.config.options('int', {
                'step': 320,
                'level': 8
            })

        # self.cw = self.ch = self.sw = self.sh = 0
        # self.start = 0

    def afterUpdate(self):
        tw = th = 0

        # if self.cw == 0:
        #     self.cw = self.refs.windowW
        #     self.ch = self.refs.windowH
        #     self.sw = self.cw
        #     self.sh = self.ch

        if not self.config.active:
            tw = self.refs.windowW
            th = self.refs.windowH
        else:
            tw = self.config.level * self.config.step
            th = round(tw * self.refs.windowH / self.refs.windowW)

            # ct = time.perf_counter()
            # if self.cw != tw or self.ch != th:
            #     self.sw = self.cw
            #     self.sh = self.ch
            #     self.cw = tw
            #     self.ch = th
            #     self.start = ct

            # tw = ease(self.sw, tw, self.start, ct, 4)
            # th = ease(self.sh, th, self.start, ct, 4)

        cw = self.refs.canvasW_
        ch = self.refs.canvasH_

        if tw != cw[0] or th != ch[0]:
            cw[0] = tw
            ch[0] = th

            self.refs.overrideW = tw
            self.refs.overrideH = th

            self.refs.windowEventCallback(
                lib.XDL_WINDOWEVENT_SIZE_CHANGED, self.refs.userData_[0])

            self.refs.overrideW = 0
            self.refs.overrideH = 0

            # hack to avoid 1 frame of wrong text scaling
            self.refs.scaleX = tw / self.refs.windowW
            self.refs.scaleY = th / self.refs.windowH
