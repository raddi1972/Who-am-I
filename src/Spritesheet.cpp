#include "Spritesheet.h"


Spritesheet::Spritesheet(const char* path, int row, int column)
{
	m_spritesheet = SDL_LoadBMP(path);

	m_clipx = m_spritesheet->w / (double)column;
	m_clipy = m_spritesheet->h / (double)row;

	m_clip.w = m_clipx;
	m_clip.h = m_clipy;
}

Spritesheet::~Spritesheet()
{
	SDL_FreeSurface(m_spritesheet);
}

void Spritesheet::selectSprite(int x, int y)
{
	m_clip.x = (double)x * m_clipx;
	m_clip.y = (double)y * m_clipy;

}

void Spritesheet::drawSelectedSprite(SDL_Surface* surface, SDL_Rect* position)
{
	SDL_BlitSurface(m_spritesheet, &m_clip, surface, position);

}



