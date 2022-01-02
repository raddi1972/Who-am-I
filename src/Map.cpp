#include "Map.h"

Map::Map(const char* path, int length, int height)
{

	m_map = SDL_LoadBMP(path);

	m_curOffsetX = 0;
	m_curOffsetY = 0;

	m_clip.w = length;
	m_clip.h = height;
}

Map::~Map()
{
	SDL_FreeSurface(m_map);
}

void Map::moveMap(int x, int y)
{
	m_clip.x = x;
	m_clip.y = y;
}

void Map::drawMap(SDL_Surface* surface)
{
	SDL_Rect position;
	position.x = 0;
	position.y = 0;
	position.w = 1845;
	position.h = 1038;
	SDL_BlitSurface(m_map, &m_clip, surface, &position);

}


