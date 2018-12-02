// paths are relative to the build dir

#include "../cdefs/internals.h"
#include "../cdefs/generated.h" // needed to define enum values
#include "../cdefs/XDL.h"

#include "../libs/subhook/subhook.h"
#include "../libs/plthook/plthook.h"

#ifdef MS_WIN32
	#include "../libs/SDL/include/SDL.h"
#else
	#include <SDL2/SDL.h>
#endif

#ifndef MS_WIN32

#include <dlfcn.h>

CFFI_DLLEXPORT int SDL_Init(uint32_t flags) {
	kickstart();
	return ((int(*)(uint32_t))dlsym(RTLD_NEXT, "SDL_Init"))(flags);
}

#endif
