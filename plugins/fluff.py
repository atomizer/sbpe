from _remote import ffi, lib
from manager import PluginBase
import util


class Plugin(PluginBase):
    def onInit(self):
        self.info = util.MultilineText(size=20, spacing=0)
        self.frame = 0

    def afterUpdate(self):
        self.frame += 1
        lst = []

        if self.refs.topTypes[0] != 'GameClient':
            lst.append('top: ' + str(self.refs.topTypes))

        cw = self.refs.ClientWorld
        if cw != ffi.NULL:
            props = cw.asWorld.props

            deco = props.decoration
            if deco != ffi.NULL:
                lst.append('dname "{}" color {:X}'.format(
                    util.getstr(deco.name), deco.backgroundcolor))

            lst.append('zone "{}" music "{}"'.format(
                util.getstr(props.zone), util.getstr(props.music)))
            lst.append('floor: {}'.format(props.floor))

            # d = util.sVecMap2list(cw.clientSubWorlds)
            # lst.append('clients: {}'.format(len(d)))
            # d = util.worldobjects(cw.mySubWorld.asNativeSubWorld)
            # lst.append('my objs: {}'.format(len(d)))
            d = util.worldobjects(cw.serverSubWorld)
            lst.append('server objs: {}'.format(len(d)))

        # for x in dir(obj):
        #     attr = getattr(obj, x)
        #     if ffi.typeof(attr) == ffi.typeof('struct STDString *'):
        #         attr = "'{}'".format(util.getstr(attr))
        #     lst.append('  {}: {}'.format(x, attr))

        self.info.text = '\n'.join(lst)

    def onPresent(self):
        self.info.draw(10, 30)
