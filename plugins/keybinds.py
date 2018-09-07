import logging

from _remote import ffi, lib
from manager import PluginBase
import util


class Plugin(PluginBase):
    def onInit(self):
        num = ffi.new('int *')
        self.keyStates = lib.SDL_GetKeyboardState(num)
        self.numKeys = num[0]
        self.oldKeys = ffi.new('uint8_t[]', self.numKeys)

        self.binds = {}
        for desc, key in self.config._section.items():
            k = lib.SDL_GetScancodeFromName(key.encode())
            if k == 0:
                logging.error('key name not recognized: "{}"'.format(key))
                continue
            desc = desc.split()
            if len(desc) <= 3:
                logging.error('not enough parameters: {}'.format(desc))
            b = {
                'plugin': 'plugin_' + desc[0],
                'option': desc[1],
                'type': desc[2],
                'values': desc[3:]
            }
            if k in self.binds:
                self.binds[k].append(b)
            else:
                self.binds[k] = [b]

    def beforeUpdate(self):
        if not lib.SDL_IsTextInputActive():
            ffi.memmove(self.oldKeys, self.keyStates, self.numKeys)

    def afterUpdate(self):
        if lib.SDL_IsTextInputActive():
            return

        plugs = self.refs.manager._active  # yeahhhh this kinda sucks

        for k in self.binds:
            diff = self.keyStates[k] - self.oldKeys[k]
            if diff == 0:
                continue

            for bind in self.binds[k]:
                pname = bind['plugin']
                if pname not in plugs:
                    continue
                conf = plugs[pname].config
                opt = bind['option']
                if opt not in conf._schema:
                    logging.error('no option "{}" in "{}"'.format(opt, pname))
                    continue
                t = bind['type']
                vals = bind['values']
                val = None
                if t == 'set' and diff > 0:
                    val = vals[0]
                elif t == 'hold':
                    if diff > 0:
                        val = vals[0]
                    else:
                        val = vals[1]
                elif t == 'toggle' and diff > 0:
                    i = 0
                    try:
                        i = vals.index(conf._section[opt]) + 1
                    except ValueError:
                        pass
                    if i >= len(vals):
                        i = 0
                    val = vals[i]

                if val is not None:
                    conf._section[opt] = val
                    if opt in conf._cache:
                        del conf._cache[opt]
