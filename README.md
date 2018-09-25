# sbppf

a.k.a. starbreak python plugin framework, a.k.a. i suck at naming things

current features:

- zoom, faster and more compatible than sbzoom
- minimap
- custom status hud
- 2 modes of centered camera, inbounds or not
- "admin key" settings are persistent in config
- disabled autokick
- mouse works at any zoom, auto-hides on inactivity
- fps, net lag indicators
- mipmapping (smooth seamless textures when zooming)

most things are configurable and keybindable, see

## `config.ini`

Use `yes` and `no` for booleans.
For colors, use hexadecimal `rgb` or `rrggbb` or `aarrggbb`. Use `0` for
"fully transparent"; `000` and `000000` are "opaque black".
If needed, see plugin sources for exact types of their options.

Any option that changes text size can be set to 0 to hide the element.

For keybinds, the format is `plugin option type value1 [value2...] = keyname`.
Valid types are:

- `set`: set the option to `value1` on press
- `hold`: set the option to `value1` when held, to `value2` when released
- `toggle`: cycle the option to the next value every press

Key names are listed here (first column): https://wiki.libsdl.org/SDL_Scancode

All options except keybinds and the `[general]` section will be reloaded
whenever the config file is changed.

Set `enabled = no` in any plugin section to disable loading of that plugin.
Don't keybind it, it will not react instantly. Plugins should use separate
options for "enabledness", for examples see map, zoom.

## running

- set correct game path in `config.ini`
- open `run.bat`

## mipmaps and sprite editing

When mipmaps are enabled, default sprite sheets are not loaded. However, you
can continue editing them and use your modifications.

To see default sprites, disable mipmaps (`mipmaps = no`).
To re-generate mipmaps and reduce distortions when zooming, enable mipmaps
and delete this file: `data/texture/DataVersion.m.bpb` (note the m!)

## compiling

performance is better when compiled with pypy

dependencies:

- python 3.5+ (32 bit on Windows, 64 bit on Linux/Mac)
- a C compiler that can be found by disttools
- `cffi` (built-in on pypy): `python -m pip install --upgrade cffi`
- SDL: install [development libraries](https://libsdl.org/download-2.0.php) for the version used by the game
    - Windows: unzip [this](https://libsdl.org/release/SDL2-devel-2.0.4-VC.zip) to `libs/SDL`
    - Linux: ?
    - Mac: ???
- `libs/subhook`: source [here](https://github.com/Zeex/subhook), don't build

to compile, run `builder.py`.

## writing plugins

_insert a tutorial of some sort here_

There is live-reloading for plugins. In case of uncaught exceptions, traceback
is written to `remote.log`. The plugin that caused the error is unloaded until
it is edited.

for plugin ideas see `notes.txt`

## external tools used

- pypy: https://pypy.org
- cffi: https://cffi.readthedocs.io
- symquery: part of https://github.com/DynamoRIO/drmemory
- mayhem: https://github.com/zeroSteiner/mayhem
- subhook: https://github.com/Zeex/subhook
- plthook: https://github.com/kubo/plthook (not actually used atm)
