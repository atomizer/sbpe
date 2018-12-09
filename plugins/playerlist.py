import time

from _remote import ffi, lib
from manager import PluginBase
import util


SHELL_ABBREV = {
    'soldier': 'W',
    'assassin': 'D',
    'heavy': 'I',
    'fabricator': 'F',
    'toaster': 'T',
    'spark': ''
}

SHELL_MIN_HP = {
    'soldier': 80,
    'assassin': 50,
    'heavy': 100,
    'fabricator': 60
}

COLUMNS = 'shell name faction'.split()


class Plugin(PluginBase):
    def onInit(self):
        self.config.option('visible', False, 'bool')
        self.config.option('size', 14, 'int')
        self.columns = {}
        for cname in COLUMNS:
            self.columns[cname] = util.MultilineText(
                size=self.config.size, spacing=self.config.size)

        self.seen = {}
        self.ct = 0

    def afterUpdate(self):
        cw = self.refs.ClientWorld
        if cw == ffi.NULL:
            return

        if cw.asWorld.props.safe:
            # wipe old records in safe zones
            self.seen = {}

        self.ct = time.perf_counter()

        allies = util.vec2list(cw.allies, 'struct WorldObject *')
        for obj in allies:
            p = obj.props
            if p.playerdata == ffi.NULL:
                continue
            acc = util.getstr(p.playerdata.accountid)
            name = util.getstr(p.displayname) or '#' + acc[:6]
            faction = util.getstr(p.playerdata.factionname)

            shell = ''
            vid = util.getstr(p.vid)
            try:
                shell = SHELL_ABBREV[vid]
            except KeyError:
                shell = '?'
            if vid in SHELL_MIN_HP and p.maxhitpoints > 0:
                mk = 1 + (p.maxhitpoints - SHELL_MIN_HP[vid]) // 10
                mk = min(mk, 6)
                # using implants on unmaxed shell
                if mk == 6 and p.maxhitpoints % 5 != 0:
                    mk = 5
                shell += str(mk)
            wasSpark = True if shell == '' else False
            self.seen[acc] = (self.ct, name, faction, shell, wasSpark)

    def onPresent(self):
        plst = list(self.seen.values())

        cw = self.refs.ClientWorld
        if cw != ffi.NULL and cw.asWorld.props.safe:
            # wipe old records in safe zones
            self.seen = {}

        if not self.config.visible:
            return

        plst.sort(key=lambda x: str.lower(x[1]))
        plst.sort(key=lambda x: str.lower(x[2]))
        plst.sort(key=lambda x: x[0], reverse=True)

        ntxt = stxt = ftxt = ''

        def addList(name, lst):
            nonlocal ntxt, ftxt, stxt
            lst = list(lst)
            if len(lst) == 0:
                return
            stxt += '{} {}\n'.format(len(lst), name)
            ntxt += '\n'
            ftxt += '\n'
            for x in lst:
                ntxt += x[1] + '\n'
                ftxt += x[2] + '\n'
                stxt += x[3] + '\n'

        addList('shells', filter(lambda x: x[0] == self.ct and x[3] != '', plst))
        addList('sparks', filter(lambda x: x[0] == self.ct and x[3] == '', plst))
        addList('seen before', filter(lambda x: x[0] != self.ct and not x[4], plst))
        addList('dead', filter(lambda x: x[0] != self.ct and x[4], plst))

        self.columns['shell'].text = stxt
        self.columns['name'].text = ntxt
        self.columns['faction'].text = ftxt

        x = self.refs.windowW // 2
        y = 10

        self.columns['shell'].draw(x - 5, y, anchorX=1)
        self.columns['name'].draw(x, y)
        self.columns['faction'].draw(x + 100, y)
