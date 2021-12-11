#pragma once

#ifdef WINDOWS_BUILD
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_timer.h>
#else
#include "SDL2.framework/Headers/SDL.h"
#include "SDL2_image.framework/Headers/SDL_image.h"
#include "SDL2.framework/Headers/SDL_timer.h"

#endif
SDL_Surface* loadSurface(const char* path);

