#include "Crawlid.h"

Crawlid::Crawlid(Vec2D pos, double length, double bredth)
	:Enemy(pos, 1, length, bredth, 1, 2), walker("crawlid.bmp", 1, 4), walker_inv("crawlid_inv.bmp", 1, 4)
{
	m_Position.x = 0;
	m_Position.y = 0;
	m_Position.w = getLength();
	m_Position.h = getBredth();

	this->vel.x = 5;

	walk.push_back(std::pair<int, int>(0, 0));
	walk.push_back(std::pair<int, int>(1, 0));
	walk.push_back(std::pair<int, int>(2, 0));
	walk.push_back(std::pair<int, int>(3, 0));
}

Crawlid::~Crawlid()
{
}

void Crawlid::draw(SDL_Surface* surface, int x, int y)
{
	m_Position.x = pos.x - getLength() / 2;
	m_Position.y = pos.y - getBredth() / 2;
	m_Position.w = getLength();
	m_Position.h = getBredth();

	if (vel.x < 0 && vel.x > -5) vel.x -= 5;
	if (vel.x > 0 && vel.x < 5) vel.x += 5;

	if (isFacingRight) {
		walker_inv.drawSelectedSprite(surface, &m_Position);
	}
	else {
		walker.drawSelectedSprite(surface, &m_Position);
	}
}

void Crawlid::update(double delta_time)
{
	timepassed += delta_time;


	if (vel.x > 0 && timepassed > 0.5) {
		w++;
		w %= walk.size();
		walker_inv.selectSprite(walk[w].first, walk[w].second);
		timepassed = 0;
		isFacingRight = true;
	}

	if (vel.x < 0 && timepassed > 0.5) {
		w++;
		w %= walk.size();
		walker.selectSprite(3 - walk[w].first, walk[w].second);
		timepassed = 0;
		isFacingRight = false;
	}

}
