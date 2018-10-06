import math

from _remote import ffi, lib
from manager import PluginBase
import util

GL_POLYGON_SMOOTH = 0x0B41
GL_POLYGON_SMOOTH_HINT = 0x0C53
GL_NICEST = 0x1102
# self.refs.glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST)


def getObjColor(obj, config, player, allies):
    p = obj.props

    # enemies
    if p.ownertype == lib.OWNERTYPE_ENEMY:
        if p.damage > 0:
            return config.enemy
        elif p.hitboxdamage == 0:
            return config.enemy_harmless

    if p.lifetime > 0 and p.interact == 0 and p.terraintype == 0:
        return 0

    # players
    # checking terrain to ignore VQ boss buildings in this section
    if p.ownertype == lib.OWNERTYPE_PLAYER and p.terraintype == 0:
        if obj == player:
            return config.player_self
        elif obj in allies:
            return config.player
        # everything else owned by shells (bullets, antiphons, etc)
        return 0

    if p.terraintype == lib.TERRAIN_PLATFORM:
        return config.platform
    if p.terraintype == lib.TERRAIN_LEDGE:
        return config.ledge

    if p.interact:
        desc = p.interactdescription
        if desc == ffi.NULL:
            return config.interact
        if desc.type == lib.INTERACTTYPE_OPEN_CHEST:
            return config.chest
        if desc.type == lib.INTERACTTYPE_ITEM:
            return config.item
        return config.interact

    if p.trigger:
        return config.trigger

    return 0


class Plugin(PluginBase):
    def onInit(self):
        self.config.option('visible', True, 'bool')
        self.config.option('hide_outside_zones', True, 'bool')
        self.config.option('antialias', False, 'bool')
        self.config.options('float', {
            'px': 1,
            'py': 1,
            'w': 0.3,
            'h': 0.3,
            'small_room': 1.5
        })
        self.config.options('color', {
            'bg': 0x80000000,
            'platform': 0xffffffff,
            'ledge': 0xffaaaaaa,
            'enemy': 0xffff0000,
            'enemy_harmless': 0xffff8000,
            'player': 0xffffff00,
            'player_self': 0xff00ff00,
            'interact': 0xff00ffff,
            'trigger': 0xffff00ff,
            'chest': 0xff0080ff,
            'item': 0xff0000ff,
        })
        self.config.option('text_size', 20, 'int')
        self.txt = util.PlainText()

    def onPresent(self):
        def drawShape(xmp, ymp, wmp, hmp, color, shapetype=lib.SHAPE_RECT):
            # rounding down/up to make overlaps to cover seams
            ox = scrx + math.floor(((xmp >> 8) - bounds.x) * scale)
            oy = scry + math.floor(((ymp >> 8) - bounds.y) * scale)
            ow = math.ceil((wmp >> 8) * scale)
            oh = math.ceil((hmp >> 8) * scale)

            if shapetype == lib.SHAPE_RECT:
                self.refs.XDL_FillRect(
                    ox, oy, ow, oh,
                    color, lib.BLENDMODE_BLEND)
            elif shapetype == lib.SHAPE_LR_TRI:
                self.refs.XDL_FillTri(
                    ox + ow, oy, ox + ow, oy + oh, ox, oy + oh,
                    color, lib.BLENDMODE_BLEND)
            elif shapetype == lib.SHAPE_LL_TRI:
                self.refs.XDL_FillTri(
                    ox, oy, ox + ow, oy + oh, ox, oy + oh,
                    color, lib.BLENDMODE_BLEND)
            elif shapetype == lib.SHAPE_UL_TRI:
                self.refs.XDL_FillTri(
                    ox, oy, ox + ow, oy, ox, oy + ow,
                    color, lib.BLENDMODE_BLEND)
            elif shapetype == lib.SHAPE_UR_TRI:
                self.refs.XDL_FillTri(
                    ox, oy, ox + ow, oy, ox + ow, oy + oh,
                    color, lib.BLENDMODE_BLEND)

        def drawObjects(subworld):
            for obj in util.worldobjects(subworld):
                color = getObjColor(obj, self.config, cw.player, allies)
                if color == 0:
                    continue
                p = obj.props
                drawShape(p.xmp, p.ymp, p.wmp, p.hmp, color, p.shapetype)

        def drawTxt():
            zone = util.getstr(cwprops.zone) or util.getstr(cwprops.music)
            self.txt.size = self.config.text_size
            self.txt.text = '{} {}'.format(zone, cwprops.floor + 1)

            # correcting position since scr[xywh] are in canvas coords
            # self.txt.draw((scrx + scrw) / self.refs.scaleX - 4,
            #               (scry + scrh) / self.refs.scaleY - 4,
            #               anchorX=1, anchorY=1)
            # ...or just put it in the corner
            self.txt.draw(self.refs.windowW - 4, self.refs.windowH - 4,
                          anchorX=1, anchorY=1)

        # actual onPresent starts here
        if self.config.visible is False:
            return

        wc = self.refs.WorldClient
        if wc == ffi.NULL or wc.overlay != ffi.NULL:
            return
        cw = wc.clientWorld
        wv = wc.worldView
        if cw == ffi.NULL or wv == ffi.NULL or cw.player == ffi.NULL:
            return

        cwprops = cw.asWorld.props
        if self.config.hide_outside_zones and cwprops.safe:
            return

        canvasW = self.refs.canvasW_[0]
        canvasH = self.refs.canvasH_[0]
        bounds = wv.worldBounds

        scale = min(self.config.w * canvasW / bounds.w,
                    self.config.h * canvasH / bounds.h)
        scrw = round(scale * bounds.w)
        scrh = round(scale * bounds.h)
        scrx = round(self.config.px * canvasW - scrw / 2)
        scry = round(self.config.py * canvasH - scrh / 2)
        scrx = max(0, min(canvasW - scrw, scrx))
        scry = max(0, min(canvasH - scrh, scry))

        # compare room size to current viewport
        roomscale = max(bounds.w / canvasW, bounds.h / canvasH)
        if roomscale < self.config.small_room:
            drawTxt()
            return

        allies = util.vec2list(cw.allies)

        if self.config.antialias:
            # force flush
            self.refs.XDL_DrawPoint(-1, -1, 0, lib.BLENDMODE_BLEND)
            self.refs.glEnable(GL_POLYGON_SMOOTH)

        # background
        self.refs.XDL_FillRect(
            scrx, scry, scrw, scrh, self.config.bg, lib.BLENDMODE_BLEND)

        # server world
        drawObjects(cw.serverSubWorld)

        # hitboxes
        ahb = util.vec2list(cw.activeHitboxes.hitboxes, 'struct ActiveHitbox')
        for box in ahb:
            if box.damage > 0:
                r = box.rectmp
                drawShape(r.x, r.y, r.w, r.h, self.config.enemy)

        # other player worlds
        worlds = util.sVecMap2list(
            cw.clientSubWorlds, 'struct ForeignSubWorld *')
        for csubworld in worlds:
            drawObjects(csubworld)

        # our player world
        drawObjects(cw.mySubWorld.asNativeSubWorld)

        if self.config.antialias:
            # force flush
            self.refs.XDL_DrawPoint(-1, -1, 0, lib.BLENDMODE_BLEND)
            self.refs.glDisable(GL_POLYGON_SMOOTH)

        # info text
        drawTxt()
