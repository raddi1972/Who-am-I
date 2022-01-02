#pragma once
#include <SDL.h>

class Map
{

private:
	SDL_Rect m_clip;
	SDL_Surface* m_map;
	double m_curOffsetX;
	double m_curOffsetY;

public:
	Map(const char* path, int length, int height);
	~Map();

	void moveMap(int x, int y);
	void drawMap(SDL_Surface* surface);


};

