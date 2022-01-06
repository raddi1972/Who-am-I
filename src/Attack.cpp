#include "Attack.h"

Attack::Attack(Vec2D pos) : Object(pos, {0, 0}, 0, 82, 82, 0), sp("effect.bmp", 5, 5)
{

	m_Position.x = 0;
	m_Position.y = 0;
	m_Position.w = getLength();
	m_Position.h = getBredth();

	attack.push_back(std::pair<int, int>(0, 0));
	attack.push_back(std::pair<int, int>(1, 0));
	attack.push_back(std::pair<int, int>(2, 0));
	attack.push_back(std::pair<int, int>(3, 0));
	attack.push_back(std::pair<int, int>(4, 0));
	attack.push_back(std::pair<int, int>(0, 1));
	attack.push_back(std::pair<int, int>(1, 1));
	attack.push_back(std::pair<int, int>(2, 1));
	attack.push_back(std::pair<int, int>(3, 1));
	attack.push_back(std::pair<int, int>(4, 1));
	attack.push_back(std::pair<int, int>(0, 2));
	attack.push_back(std::pair<int, int>(1, 2));
	attack.push_back(std::pair<int, int>(2, 2));
	attack.push_back(std::pair<int, int>(3, 2));
	attack.push_back(std::pair<int, int>(4, 2));
	attack.push_back(std::pair<int, int>(0, 3));
	attack.push_back(std::pair<int, int>(1, 3));
	attack.push_back(std::pair<int, int>(2, 3));
	attack.push_back(std::pair<int, int>(3, 3));
	attack.push_back(std::pair<int, int>(4, 3));
	attack.push_back(std::pair<int, int>(0, 4));
	attack.push_back(std::pair<int, int>(1, 4));
	attack.push_back(std::pair<int, int>(2, 4));
	attack.push_back(std::pair<int, int>(3, 4));
	attack.push_back(std::pair<int, int>(4, 4));
}

Attack::~Attack()
{
}

void Attack::update(double delta_time)
{
	timepassed += delta_time;
	if (timepassed >= 0.1) {
		a++;
		a %= attack.size();
		sp.selectSprite(attack[a].first, attack[a].second);
		timepassed = 0;
	}

}

void Attack::draw(SDL_Surface* surface, int x, int y)
{
	m_Position.x = pos.x - getLength() / 2;
	m_Position.y = pos.y - getBredth() / 2;
	sp.drawSelectedSprite(surface, &m_Position);
}
