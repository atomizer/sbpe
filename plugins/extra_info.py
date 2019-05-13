import logging
import math
import time

from _remote import ffi, lib
from manager import PluginBase
import util

TARGETS = {
    'door': '''
        cave.nextDoor cave.bossgate
        city.nextDoor city.bossgate
        dumb.nextDoor dumb.bossgate
        forest.nextdoor forest.unextdoor forest.bossgate
        hulk.door3 hulk.prevdoor hulk.hportalbase
        ice.nextDoor ice.bossgate
        jungle.door jungle.bossgate
        lab.nextdoor lab.bossgate
        sc.door
    ''',

    'shop': '''
        dumb.secretspot dumb.secretspoton
        hulk.sspot hulk.sdopen
        jungle.sspot jungle.sdopen
        lab.sspot lab.sspotdone
    ''',

    'secret': '''
        cave.sd
        city.sd
        dumb.fw
        forest.sspot forest.sdopen
        hulk.sd2
        jungle.sd2
        lab.sd2
    ''',

    'arcade': '''
        forest.miner
        dumb.steletop
        hulk.sg
        lab.sg
    ''',

    'player': 'soldier assassin heavy fabricator toaster',

    'hp': 'loot-health1 loot-xmas',

    'boost': ''
}

TVIDMAP = {}

for k in TARGETS:
    klist = TARGETS[k].split()
    for vid in klist:
        TVIDMAP[vid] = k

BOOSTS = {
    # vid : (PlayerCharacter attribute, CharacterDescription attribute)
    'loot-maxhealth': ('maxHitpoints', 'maxhitpoints'),
    'loot-maxammo': ('maxAmmo', 'maxammo'),
    'loot-damage': ('damageBonus', 'damagebonus'),
    'loot-armor': ('armor', 'armor'),
    'loot-mspeed': ('walkSpeed', 'walkspeed'),
    'loot-jheight': ('jumpSpeed', 'jumpspeed'),
    'loot-critchance': ('critChance', 'critchance'),
    'loot-critmult': ('critMult', 'critmult'),
}

OPTS = (
    ('color', 0xffffffff, 'color'),
    ('length', 20, 'float'),
    ('width', 10, 'float'),
    ('outline', 2, 'float'),
    ('fade', 300, 'int'),
    ('frame', 5, 'float'),
    ('blink', 0, 'float')
)


def rotate(x, y, angle):
    rx = x * math.cos(angle) - y * math.sin(angle)
    ry = x * math.sin(angle) + y * math.cos(angle)
    return (rx, ry)


class Plugin(PluginBase):
    def onInit(self):
        self.config.option('trigger_color', 0xffff00ff, 'color')
        self.config.option('trigger_frame', 3, 'int')

        self.config.option('arrows', '', 'str')

        for opt in OPTS:
            self.config.option('arrows_' + opt[0], opt[1], opt[2])

        self.config.option('show_hp', False, 'bool')
        self.config.option('show_uses', True, 'bool')
        self.config.option('show_room_id', True, 'bool')

        self._initedopts = False
        self.numbers = util.NumberDict(size=16, color=0xffff80)
        self.negnumbers = util.NumberDict(size=16, color=0x8080ff)
        self.roomtxt = util.PlainText(size=16)

    def onPresent(self):
        if not self._initedopts:
            self._initedopts = True
            for k in TARGETS.keys():
                for opt in OPTS:
                    self.config.option(
                        'arrow_{}_{}'.format(k, opt[0]),
                        self.config['arrows_' + opt[0]], opt[2])

        cw = self.refs.ClientWorld
        wv = self.refs.WorldView
        if cw == ffi.NULL or wv == ffi.NULL:
            return

        plr = cw.player
        if plr == ffi.NULL:
            return
        if util.getClassName(plr) not in self.refs.CASTABLE['PlayerCharacter']:
            return
        plr = ffi.cast('struct PlayerCharacter *', plr)

        objects = util.worldobjects(cw.serverSubWorld)
        objects += util.worldobjects(cw.mySubWorld.asNativeSubWorld)
        objects += util.vec2list(cw.allies, 'struct WorldObject *')

        kinds = self.config.arrows.split()

        for obj in objects:
            p = obj.props
            vid = util.getstr(p.vid)

            # invisible
            if len(vid) == 0:
                # triggers
                if p.trigger != 0:
                    self.drawFrame(
                        obj, self.config.trigger_color,
                        self.config.trigger_frame)
                # otherwise skip
                continue

            w2 = p.wmp // 512
            h2 = p.hmp // 512
            x = p.xmp // 256 + w2 - wv.offset.x
            y = p.ymp // 256 + h2 - wv.offset.y
            inbounds = x + w2 > 0 and y + h2 > 0 and\
                x - w2 < self.refs.canvasW_[0] and\
                y - h2 < self.refs.canvasH_[0]

            # object hp/armor
            if inbounds and self.config.show_hp:
                if p.hitpoints >= 0:
                    self.numbers.draw(
                        p.hitpoints, x, y, anchorX=0.5, anchorY=1)
                elif p.hitpoints != -1:
                    self.negnumbers.draw(
                        abs(p.hitpoints), x, y, anchorX=0.5, anchorY=1)

                if p.armor > 0:
                    self.numbers.draw(p.armor, x, y, anchorX=0.5, anchorY=0)

            # use counts
            if inbounds and self.config.show_uses and p.interact != 0:
                idesc = p.interactdescription
                if idesc != ffi.NULL and idesc.numused > 0 and\
                        idesc.totaluses > 0:
                    self.numbers.draw(
                        idesc.numused, x, y, anchorX=0.5, anchorY=0.5)

            # boosts
            if 'boost' in kinds and vid[:-1] in BOOSTS:
                btype = BOOSTS[vid[:-1]]
                blevel = int(vid[-1])

                # current value: StatVal from PlayerCharacter
                currvalue = getattr(plr, btype[0]).base

                # max values list: RepeatedField_int from CharacterDescription
                mvals = getattr(plr.charDesc, btype[1])
                mvals = ffi.unpack(mvals.elements, mvals.current_size)

                for i in range(1, len(mvals)):
                    if mvals[i] > currvalue and i <= blevel:
                        self.drawArrow(plr, obj, 'boost')
                        break

                continue

            # match vid name with target list
            try:
                k = TVIDMAP[vid]
            except KeyError:
                continue

            # consider only enabled types
            if k not in kinds:
                continue

            # do we need hp?
            if k == 'hp':
                plrprops = ffi.cast('struct WorldObject *', plr).props
                if plrprops.hitpoints == plrprops.maxhitpoints:
                    continue

            # all checks passed, we are interested in this obj
            self.drawArrow(plr, obj, k)

        # zone/room id
        if self.config.show_room_id:
            cwprops = cw.asWorld.props
            txt = util.getstr(cwprops.zone) or util.getstr(cwprops.music)
            if cwprops.floor > 0:
                txt = '{} {}'.format(txt, cwprops.floor + 1)
            self.roomtxt.text = txt
            self.roomtxt.draw(
                self.refs.windowW - 4, self.refs.windowH - 4,
                anchorX=1, anchorY=1)

    def drawArrow(self, src, dst, kind):
        optprefix = 'arrow_' + kind + '_'

        offset = self.refs.WorldView.offset
        cw = self.refs.canvasW_[0]
        ch = self.refs.canvasH_[0]

        sp = ffi.cast('struct WorldObject *', src).props
        dp = ffi.cast('struct WorldObject *', dst).props

        dw2 = dp.wmp // 512
        dh2 = dp.hmp // 512
        x1 = (dp.xmp) // 256 + dw2 - offset.x
        y1 = (dp.ymp) // 256 + dh2 - offset.y

        inbounds = (x1 + dw2 >= 0 and x1 - dw2 <= cw and y1 + dh2 >= 0 and y1 - dh2 <= ch)

        if inbounds and self.config[optprefix + 'frame'] == 0:
            return

        if inbounds:
            x0 = (sp.xmp + sp.wmp // 2) // 256 - offset.x
            y0 = (sp.ymp + sp.hmp // 2) // 256 - offset.y
        else:
            x0 = cw // 2
            y0 = ch // 2

        angle = math.atan2(y1 - y0, x1 - x0)

        # offset target position to the canvas edges if out of bounds
        t = 1
        if x1 < 0 and x0 != x1:
            t = min(t, x0 / (x0 - x1))
        if y1 < 0 and y0 != y1:
            t = min(t, y0 / (y0 - y1))
        if x1 > cw and x0 != x1:
            t = min(t, (cw - x0) / (x1 - x0))
        if y1 > ch and y0 != y1:
            t = min(t, (ch - y0) / (y1 - y0))
        # arrow point coords
        ax = x0 + t * (x1 - x0)
        ay = y0 + t * (y1 - y0)

        # fading
        dist = math.sqrt((ax - x0) ** 2 + (ay - y0) ** 2)
        fade = self.config[optprefix + 'fade']
        color = self.config[optprefix + 'color']
        f = 1
        if dist < fade and fade > 0:
            f = dist / fade
        # blinking
        bp = self.config[optprefix + 'blink']
        if bp > 0:
            f = f * abs(time.perf_counter() % bp - bp / 2) * 2 / bp

        if f < 1:
            ca = math.floor((color >> 24) * f) & 0xff
            color = (color & 0xffffff) | (ca << 24)

        # draw frame
        if inbounds:
            self.drawFrame(dst, color, self.config[optprefix + 'frame'])
            return

        # draw triangle
        dx = self.config[optprefix + 'length'] * self.refs.scaleX
        dy = self.config[optprefix + 'width'] / 2 * self.refs.scaleX

        # outline
        out = self.config[optprefix + 'outline'] * self.refs.scaleX
        if out > 0:
            offx = out / math.tan(math.pi / 4 - math.atan2(dx, dy) / 2)
            offy = out / math.tan(math.pi / 4 - math.atan2(dy, dx) / 2)
            (oax, oay) = rotate(offx, 0, angle)
            (obx, oby) = rotate(-dx - out, dy + offy, angle)
            (ocx, ocy) = rotate(-dx - out, -dy - offy, angle)
            self.refs.XDL_FillTri(
                round(ax + oax), round(ay + oay),
                round(ax + obx), round(ay + oby),
                round(ax + ocx), round(ay + ocy),
                color & 0xff000000, lib.BLENDMODE_BLEND)

        # middle
        (bx, by) = rotate(-dx, dy, angle)
        (cx, cy) = rotate(-dx, -dy, angle)
        self.refs.XDL_FillTri(
            round(ax), round(ay),
            round(ax + bx), round(ay + by),
            round(ax + cx), round(ay + cy),
            color, lib.BLENDMODE_BLEND)

    def drawFrame(self, obj, color, width):
        if color == 0 or width <= 0:
            return

        blend = lib.BLENDMODE_ADD
        p = obj.props
        wv = self.refs.WorldView
        x = p.xmp // 256 - wv.offset.x
        y = p.ymp // 256 - wv.offset.y
        w = p.wmp // 256
        h = p.hmp // 256

        cw = self.refs.canvasW_[0]
        ch = self.refs.canvasH_[0]
        if x + w < 0 or y + h < 0 or x > cw or y > ch:
            return

        lw = max(1, round(width * self.refs.scaleX))
        if lw * 2 > w or lw * 2 > h:
            self.refs.XDL_FillRect(x, y, w, h, color, blend)
            return

        self.refs.XDL_FillRect(x, y, w - lw, lw, color, blend)
        self.refs.XDL_FillRect(x + lw, y + h - lw, w - lw, lw, color, blend)

        self.refs.XDL_FillRect(x, y + lw, lw, h - lw, color, blend)
        self.refs.XDL_FillRect(x + w - lw, y, lw, h - lw, color, blend)
