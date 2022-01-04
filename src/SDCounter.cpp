#include "SDCounter.h"

SDCounter::SDCounter(Vec2D pos) : countDisplay("SDCounter_sprite.bmp", 1, 10), Object({pos.x - 16, pos.y - 16}, {0,0}, 1, 32, 32, 0)
{
	count = 0;
	countDisplay.selectSprite(count, 0);
	m_position.x = 0;
	m_position.y = 0;
	m_position.w = getLength();
	m_position.h = getBredth();
}

void SDCounter::draw(SDL_Surface* surface, int x, int y)
{
	m_position.x = pos.x;
	m_position.y = pos.y;
	countDisplay.drawSelectedSprite(surface, &m_position);
}

int SDCounter::increaseCount()
{
	count++;
	count = count%10;
	countDisplay.selectSprite(count, 0);
	return count;
}

int SDCounter::decreaseCount()
{
	if(count == 0)
	{
		count = 9;
	}
	else
	{
		count--;
	}
	countDisplay.selectSprite(count, 0);
	return count;
}

int SDCounter::getCount()
{
	return count;
}
