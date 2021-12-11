#include "Helper.h"


SDL_Surface* loadSurface(const char* path)
{
	SDL_Surface* imageSurface = SDL_LoadBMP(path);

	if (!imageSurface)
		return nullptr;

	return imageSurface;
}