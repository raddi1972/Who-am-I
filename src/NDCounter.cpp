#include "NDCounter.h"

NDCounter::NDCounter(Vec2D pos) : score("Score.bmp",1,1),Object(pos, {0,0}, 1, 1, 1, 0)
{
	score.selectSprite(0,0);
	m_position.x = 0;
	m_position.y = 0;
	m_position.w = 1;
	m_position.h = 1;
	SDCounter * d0 = new SDCounter(pos);
	SDw = d0->getLength();
	digits.push_back(d0);
}

void NDCounter::draw(SDL_Surface* surface, int x, int y)
{
	m_position.x = 941;
	m_position.y = 15;
	score.drawSelectedSprite(surface, &m_position);
	for(auto d:digits)
	{
		d->draw(surface , x, y);
	}
}

void NDCounter::increaseCount()
{
	bool flag = true;
	int i = digits.size() - 1;
	while(flag)
	{
		flag = false;
		if(digits[i]->increaseCount() == 0)
		{
			flag = true;
			i--;
			if(i==-1) //Creating a new digit
			{
				i++;
				pos.x = pos.x - SDw;
				SDCounter *dNew = new SDCounter(pos);
				digits.insert(digits.begin(), dNew);
			}
		}
	}
}

void NDCounter::decreaseCount()
{
	bool masterFlag = false;
	for(auto d:digits)
	{
		if(d->getCount() != 0)
		{
			masterFlag = true;
			break;
		}
	}

	bool flag = true;
	int i = digits.size() - 1;
	while(flag && masterFlag)
	{
		flag = false;
		if(digits[i]->decreaseCount() == 9)
		{
			flag = true;
			i--;
		}
	}
}
