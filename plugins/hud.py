from _remote import ffi, lib
from manager import PluginBase
import util

ELEMS = 'hp hpmax ammo ammomax currency'.split()


class Plugin(PluginBase):
    def onInit(self):
        self.config.options('int', {
            'x': 100,
            'y': 20,
            'size_hp': 42,
            'size_hpmax': 24,
            'size_ammo': 20,
            'size_ammomax': 20,
            'size_currency': 16,
            'outline': 3,
            'spacing': 0
        })
        self.config.option('color_hp', 0xffffffff, 'color')
        self.config.option('color_hp_full', 0xff00ff00, 'color')
        self.config.option('color_ammo', 0xffffff00, 'color')
        self.config.option('color_currency', 0xff9999ff, 'color')

        for name in ELEMS:
            setattr(self, 'txt_' + name, util.PlainText(font='HemiHeadBold'))

        self.draw = False

    def afterUpdate(self):
        self.draw = False
        wc = self.refs.WorldClient
        cw = self.refs.ClientWorld
        if wc == ffi.NULL or cw == ffi.NULL or cw.player == ffi.NULL:
            return

        if wc.hud != ffi.NULL and wc.hud.hudStatus != ffi.NULL:
            ffi.cast('struct UIElement *', wc.hud.hudStatus).show = False

        ptype = util.getClassName(cw.player)
        if ptype not in self.refs.CASTABLE['PlayerCharacter']:
            return

        wobj = ffi.cast('struct WorldObject *', cw.player)
        pc = ffi.cast('struct PlayerCharacter *', cw.player)

        self.txt_hp.text = '{}'.format(wobj.props.hitpoints)
        self.txt_hpmax.text = '/{}'.format(wobj.props.maxhitpoints)

        self.txt_ammo.text = '{}'.format(pc.ammo)
        maxammo = pc.maxAmmo.base + pc.maxAmmo.bonus
        if pc.ammoMult > 1:
            self.txt_ammomax.text = '/{} (x{})'.format(maxammo, pc.ammoMult)
        else:
            self.txt_ammomax.text = '/{}'.format(maxammo)

        self.txt_currency.text = '{} EC  {} UC'.format(pc.ec, pc.uc)

        for name in ELEMS:
            el = getattr(self, 'txt_' + name)
            el.size = getattr(self.config, 'size_' + name)
            el.outlineSize = self.config.outline

        if wobj.props.hitpoints == wobj.props.maxhitpoints:
            hpcolor = self.config.color_hp_full
        else:
            hpcolor = self.config.color_hp
        self.txt_hp.color = self.txt_hpmax.color = hpcolor
        self.txt_ammo.color = self.txt_ammomax.color = self.config.color_ammo
        self.txt_currency.color = self.config.color_currency

        self.draw = True

    def onPresent(self):
        if not self.draw:
            return

        x = self.config.x
        y = self.config.y

        self.txt_hp.draw(x, y, anchorX=1, anchorY=0.5)
        self.txt_hpmax.draw(x - 4, y, anchorY=0.5)

        y = y + self.txt_hp.h + self.config.spacing

        self.txt_ammo.draw(x, y, anchorX=1, anchorY=0.5)
        self.txt_ammomax.draw(x - 4, y, anchorY=0.5)

        y = y + self.txt_ammo.h + self.config.spacing

        self.txt_currency.draw(x, y, anchorX=0.5)

    def __del__(self):
        wc = self.refs.WorldClient
        if wc != ffi.NULL and wc.hud != ffi.NULL:
            if wc.hud.hudStatus != ffi.NULL:
                ffi.cast('struct UIElement *', wc.hud.hudStatus).show = True
