import importlib
import importlib.util
import logging
import os
import re
import sys
import time
import traceback

VALID_NAME = re.compile(r'[a-z][a-z0-9_]*', re.ASCII + re.IGNORECASE)


def report_exception(src=''):
    t, ex, tb = sys.exc_info()
    lines = traceback.format_exception(t, ex, tb.tb_next)
    lines = ''.join(lines[1:])
    logging.error('exception in {}:\n{}'.format(src, lines))


class Manager(object):
    def __init__(self, path, refs):
        self.path = path
        self.refs = refs

        self.config = refs.config
        if not refs.config.has_section('manager'):
            refs.config.add_section('manager')

        self.period = self.config['manager'].getint('period', 3)
        self.priority = self.config['manager'].get('priority', '').split()

        self._active = {}
        self._mtimes = {}
        self._lastload = 0

    def run(self):
        if time.time() < self._lastload + self.period:
            return
        self._lastload = time.time()
        self.reload()

    def _reload(self, fname):
        fpath = os.path.join(self.path, fname)
        mname, mext = os.path.splitext(fname)
        if mext != '.py':  # not a module
            return False
        if VALID_NAME.fullmatch(mname) is None:  # bad file name
            return False
        # avoid any name/keyword collisions
        mname = 'plugin_' + mname
        # disable current version, if any
        if mname in self._active:
            del self._active[mname]
        # every plugin has a config section
        if not self.config.has_section(mname):
            self.config.add_section(mname)
        # check enabled status so that plugins don't need to
        if not self.config.getboolean(mname, 'enabled', fallback=True):
            return False

        # attempt to load the module
        try:
            spec = importlib.util.spec_from_file_location(mname, fpath)
            module = importlib.util.module_from_spec(spec)
            spec.loader.exec_module(module)
            self._active[mname] = module.Plugin(self.refs, self.config[mname])
        except Exception:
            report_exception(mname)
            return False

        # run custom init
        if self._runCallback(mname, 'onInit') is False:
            return False

        logging.info('loaded {}'.format(mname))
        return True

    def reload(self):
        # check config file
        if os.path.exists(self.refs.CONFIGFILE):
            cmt = os.stat(self.refs.CONFIGFILE).st_mtime
            if 'config' not in self._mtimes or self._mtimes['config'] != cmt:
                self.config.read(self.refs.CONFIGFILE)
                self._mtimes['config'] = cmt
                # check if enabled state was changed
                for name in self.config.sections():
                    if not name.startswith('plugin_'):
                        continue
                    en = self.config.getboolean(name, 'enabled', fallback=True)
                    if en is False and name in self._active:
                        # was disabled
                        del self._active[name]
                    elif en is True and name not in self._active:
                        # was enabled, force reload on next check.
                        # does not matter on first load, but will keep trying
                        # failing plugins whenever config file is edited
                        # (possible log spam).
                        self._mtimes[name[7:] + '.py'] = 0
                # reset config caches to update values on next access
                for plug in self._active.values():
                    plug.config._cache = {}
                logging.info('loaded config')

        # check plugins
        for entry in os.scandir(self.path):
            try:
                if entry.is_file() is False:
                    continue
                mtime = entry.stat().st_mtime
            except Exception:
                continue  # ignore files with permission problems
            fname = entry.name
            if fname in self._mtimes and self._mtimes[fname] == mtime:
                continue  # not modified since last check
            self._mtimes[fname] = mtime
            self._reload(fname)

    def _runCallback(self, mname, cbname):
        try:
            getattr(self._active[mname], cbname)()
            return True
        except Exception:
            report_exception('{}.{}'.format(mname, cbname))
            del self._active[mname]
            return False

    def runCallbacks(self, cbname):
        active = set(self._active.keys())
        for mname in self.priority:
            if mname not in active:
                continue
            active.remove(mname)
            self._runCallback(mname, cbname)

        for mname in active:
            self._runCallback(mname, cbname)


class PluginBase(object):
    def __init__(self, refs, config):
        self.refs = refs
        self.config = PluginConfig(config)

    def onInit(self):
        '''plugin-specific init code'''
        pass

    def beforeUpdate(self):
        '''just before the game processes events'''
        pass

    def afterUpdate(self):
        '''immediately after events'''
        pass

    def onPresent(self):
        '''after the game renders a frame'''
        pass


DEFAULTS = {
    'str': '',
    'int': 0,
    'float': 0.0,
    'bool': False,
    'color': 0
}


class PluginConfig():
    def __init__(self, section):
        self._section = section
        self._schema = {}
        self._cache = {}

    def option(self, name, default=None, type='str'):
        if type not in DEFAULTS:
            raise TypeError('unknown option type')
        if default is None:
            default = DEFAULTS[type]
        self._schema[name] = (default, type)
        if name not in self._section:
            self._putvalue(name, default)

    def options(self, type, defdict):
        for (name, default) in defdict.items():
            self.option(name, default, type)

    def __getattr__(self, name):
        try:
            return self._cache[name]
        except KeyError:
            if name not in self._schema:
                raise AttributeError('unknown option name')
            val = self._getvalue(name)
            self._cache[name] = val
            return val

    def __setattr__(self, name, value):
        if name[0] == '_' or name not in self._schema:
            object.__setattr__(self, name, value)
            return
        self._putvalue(name, value)
        # round-trip to ensure correct type
        self._cache[name] = self._getvalue(name)

    def __getitem__(self, key):
        return self.__getattr__(key)

    def _getvalue(self, name):
        default, t = self._schema[name]
        try:
            if t == 'str':
                return self._section[name]
            elif t == 'bool':
                return self._section.getboolean(name)
            elif t == 'int':
                return self._section.getint(name)
            elif t == 'float':
                return self._section.getfloat(name)
            elif t == 'color':
                val = self._section[name]
                if len(val) == 3:  # css-style short format
                    val = ''.join([x + x for x in val])
                if len(val) == 6:
                    val = 'ff' + val
                return int('0x' + val, 16)
        except Exception:
            report_exception('config.{}, using "{}"'.format(
                name, default))
            self._putvalue(name, default)  # defaults must always work
            return default

    def _putvalue(self, name, value):
        default, t = self._schema[name]
        try:
            if t == 'str' or t == 'int' or t == 'float':
                self._section[name] = str(value)
            elif t == 'bool':
                self._section[name] = 'yes' if value else 'no'
            elif t == 'color':
                if value == 0:
                    self._section[name] = '0'
                if value >> 24 >= 0xff:
                    value = value & 0xffffff
                self._section[name] = '{:06x}'.format(value)
        except Exception:
            report_exception('config.{} = {}, using "{}"'.format(
                name, value, default))
            self._putvalue(name, default)  # defaults must always work
