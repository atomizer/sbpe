import time

from _remote import ffi, lib
from manager import PluginBase
import util


def ease(start, end, stime, ctime, dur):
    t = ctime - stime
    if t > dur:
        return end
    if t < 0:
        return start
    t = t / dur
    pt = t * (2 - t)
    return start + (end - start) * pt


def toUIElement(obj):
    return ffi.cast('struct UIElement *', obj)


def setUIElementSize(elem, w, h):
    if elem == ffi.NULL:
        return
    uiel = toUIElement(elem)
    uiel.w = w
    uiel.h = h


class Plugin(PluginBase):
    def onInit(self):
        self.config.option('active', True, 'bool')
        self.config.option('level', -1, 'int')
        self.config.option('fast', True, 'bool')
        self.config.option('time', 0, 'float')

        self.start = 1
        self.target = 1
        self.stime = 0

        # allows to cleanly skip the worldclient event handler
        self._hook = 0
        if self.config.fast:
            self._hook = lib.subhook_new(
                self.refs['WorldClient::handleWindowEvent'],
                self.refs['UIElementContainer::handleWindowEvent'], 0)
            lib.subhook_install(self._hook)

    def __del__(self):
        if self._hook:
            lib.subhook_remove(self._hook)
            lib.subhook_free(self._hook)

    def afterUpdate(self):
        cw = self.refs.canvasW_
        ch = self.refs.canvasH_

        cscale = cw[0] / self.refs.windowW
        ctime = time.perf_counter()

        if not self.config.active:
            self.start = self.target = 1
            nscale = 1
        else:
            twidth = self.config.level
            targ = twidth / self.refs.windowW

            if targ <= 0:
                targ = 1

            if self.target != targ:
                self.stime = ctime
                self.start = cscale
                self.target = targ

            if self.config.time > 0:
                nscale = ease(
                    self.start, self.target,
                    self.stime, ctime, self.config.time)
            else:
                nscale = self.target

        if nscale <= 0:
            nscale = 0.1

        if nscale == cscale:
            return

        tw = round(nscale * self.refs.windowW)
        th = round(nscale * self.refs.windowH)

        cw[0] = self.refs.overrideW = tw
        ch[0] = self.refs.overrideH = th

        installed = lib.subhook_is_installed(self._hook) != 0
        if self.config.fast and not installed:
            lib.subhook_install(self._hook)
        if not self.config.fast and installed:
            lib.subhook_remove(self._hook)

        # replacement handling of window resize event for WorldClient and
        # everything inside of it that doesn't have handlers
        wc = self.refs.WorldClient
        if self.config.fast and wc != ffi.NULL:
            setUIElementSize(wc, tw, th)
            setUIElementSize(wc.worldView, tw, th)
            setUIElementSize(wc.hud, tw, th)
            setUIElementSize(wc.overlay, tw, th)
            # equip
            if wc.hud != ffi.NULL and wc.hud.hudEquip != ffi.NULL:
                equip = toUIElement(wc.hud.hudEquip)
                equip.x = tw - equip.w - 28
            # overlays
            overlay = wc.overlay
            if overlay != ffi.NULL:
                otype = util.getClassName(overlay)
                overlay = ffi.cast('struct {} *'.format(otype), overlay)

                if otype == 'InventoryOverlay':
                    inv = toUIElement(overlay.inventoryWindow)
                    inv.x = tw - inv.w - 24
                    exy = inv.y + inv.h + 24
                    stash = toUIElement(overlay.stashWindow)
                    if stash != ffi.NULL:
                        stash.x = tw - stash.w - 24
                        stash.y = exy + 6
                        exy += stash.h + 6
                    ex = toUIElement(overlay.playerWindowExitSprite)
                    ex.x = tw - ex.w
                    ex.y = exy
                    tt = toUIElement(overlay.toolTip)
                    if tt != ffi.NULL:
                        tt.x = inv.x - tt.w
                    ctt = toUIElement(overlay.comparisonToolTip)
                    if ctt != ffi.NULL:
                        ctt.x = tt.x - ctt.w

                if otype == 'ProgressOverlay':
                    pw = toUIElement(overlay.progressWindow)
                    pw.x = (tw - pw.w) // 2
                    pw.y = (th - pw.h) // 2
                    ex = toUIElement(overlay.playerWindowExitSprite)
                    ex.x = tw - ex.w
                    ex.y = pw.y + pw.h - ex.h

                if otype == 'ScoreOverlay':
                    off = int(tw * 0.4)
                    scw = toUIElement(overlay.scoreCharWindow)
                    scw.x = (off - scw.w) // 2
                    ssw = toUIElement(overlay.scoreStatsWindow)
                    ssw.x = off
                    sbw = toUIElement(overlay.scoreBonusWindow)
                    sbw.x = off + ssw.w + 30
                    fss = toUIElement(overlay.finalScoreSprite)
                    fss.x = off
                    fss.y = max(sbw.h + sbw.y, ssw.h + ssw.y) + 64
                    xpb = toUIElement(overlay.xpLevelBars)
                    if xpb != ffi.NULL:
                        xpb.x = off
                        xpb.y = fss.h + fss.y + 24
                    ex = toUIElement(overlay.playerWindowExitSprite)
                    ex.x = tw - ex.w
                    ex.y = th - ex.h - 100
                    if overlay.scoreRankAdded:
                        # the rank visual element is the last child
                        oc = ffi.cast('struct UIElementContainer *', overlay)
                        chl = util.vec2list(oc.children, 'struct UIElement *')
                        if len(chl) > 0:
                            sr = chl[-1]
                            sr.x = scw.x + scw.w - 20

                if otype == 'ZoneScoreOverlay':
                    outro = toUIElement(overlay.outro)
                    outro.x = int(tw * 0.3)
                    outro.y = int(th * 0.5)
                    hoff = int(tw * 0.3)
                    voff = int(th * 0.7)
                    kvl = util.vec2list(
                        overlay.keyValLabels, 'struct LabelPair')
                    for pair in kvl:
                        first = toUIElement(pair.first)
                        second = toUIElement(pair.second)
                        first.x = hoff - 96
                        second.x = hoff + 96 - second.w
                        first.y = second.y = voff
                        voff += 20
                    if len(kvl) > 0:
                        voff += 20
                    xpb = toUIElement(overlay.xpLevelBars)
                    xpb.x = hoff - 140
                    xpb.y = voff + 20
                    ex = toUIElement(overlay.playerWindowExitSprite)
                    ex.x = tw - ex.w
                    ex.y = th - ex.h - 100

        self.refs.windowEventCallback(
            lib.XDL_WINDOWEVENT_SIZE_CHANGED, self.refs.userData_[0])

        self.refs.overrideW = 0
        self.refs.overrideH = 0

        # hack to avoid 1 frame of wrong text scaling
        self.refs.scaleX = self.refs.scaleY = nscale
