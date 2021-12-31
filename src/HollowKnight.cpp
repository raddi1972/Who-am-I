#include "HollowKnight.h"

HollowKnight::HollowKnight()
	: image("HollowKnightSprite.bmp", 12, 12), Object({42, 42}, {0, 0}, 0.5, 85, 85, 1)
{
	image.selectSprite(0, 0);

	m_Position.x = 0;
	m_Position.y = 0;
	m_Position.w = 85;
	m_Position.h = 85;

	m_x = 0.0;
	m_y = 0.0;

	m_MovingRight = 0;

}


void HollowKnight::update(double delta_time)
{
	double multiplyer = 10.0;

	switch (m_Direction)
	{
	case Direction::NONE:
		image.selectSprite(0, 0);
		break;

	case Direction::LEFT:
		if(vel.x >= -10)
			vel.x += -3;
		break;

	case Direction::RIGHT:
		if(vel.x <= 10)
		vel.x += 3;
		break;
	}
	m_Direction = Direction::NONE;
}

void HollowKnight::draw(SDL_Surface* surface)
{
	m_Position.x = pos.x - getLength() / 2;
	m_Position.y = pos.y - getLength() / 2;
	image.drawSelectedSprite(surface, &m_Position);
}

void HollowKnight::handle_events(SDL_Event const& e)
{
	switch (e.type)
	{
	case SDL_KEYDOWN:
		Uint8 const* keys = SDL_GetKeyboardState(nullptr);

		if (keys[SDL_SCANCODE_W] == 1)
			m_Direction = Direction::UP;
		else if (keys[SDL_SCANCODE_S] == 1)
			m_Direction = Direction::DOWN;
		else if (keys[SDL_SCANCODE_A] == 1)
			m_Direction = Direction::LEFT;
		else if (keys[SDL_SCANCODE_D] == 1) {
			m_Direction = Direction::RIGHT;
		}

		break;
	}
}

HollowKnight::~HollowKnight()
{
}
