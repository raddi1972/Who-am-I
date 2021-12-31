#include "HollowKnight.h"

HollowKnight::HollowKnight()
	: image("HollowKnightSprite.bmp", 12, 12)
{
	image.selectSprite(0, 0);

	m_Position.x = 0;
	m_Position.y = 0;
	m_Position.w = 85;
	m_Position.h = 85;

	m_x = 0.0;
	m_y = 0.0;

	m_MovingRight = 0;

	curState = { {0, 0}, {0, 0}, {0, 0} };
}

void HollowKnight::update(double delta_time)
{
	double multiplyer = 10.0;

	switch (m_Direction)
	{
	case Direction::NONE:
		m_x += 0.0;
		m_y += 0.0;
		image.selectSprite(0, 0);
		break;

	case Direction::DOWN:
		m_y += multiplyer * delta_time;
		image.selectSprite(0, 0);
		break;

	case Direction::UP:
		m_y -= multiplyer * delta_time;
		image.selectSprite(0, 0);
		break;

	case Direction::LEFT:
		m_x -= multiplyer * delta_time;
		image.selectSprite(0, 1);
		break;

	case Direction::RIGHT:
		m_x += multiplyer * delta_time;
		image.selectSprite(((int)m_MovingRight / 60), 0);
		m_MovingRight += 50 * multiplyer * delta_time;
		break;
	}


	// Right logic
	if (m_MovingRight > 540)
	{
		m_MovingRight = 0;
		m_Direction = Direction::NONE;
	}

	m_Position.x = m_x;
	m_Position.y = m_y;
}

void HollowKnight::draw(SDL_Surface* surface)
{
	image.drawSelectedSprite(surface, &m_Position);
}

void HollowKnight::handle_events(SDL_Event const& event)
{
	switch (event.type)
	{
	case SDL_KEYDOWN:
		Uint8 const* keys = SDL_GetKeyboardState(nullptr);

		if (keys[SDL_SCANCODE_W] == 1)
			m_Direction = Direction::UP;
		else if (keys[SDL_SCANCODE_S] == 1)
			m_Direction = Direction::DOWN;
		else if (keys[SDL_SCANCODE_A] == 1)
			m_Direction = Direction::LEFT;
		else if (keys[SDL_SCANCODE_D] == 1)
			m_Direction = Direction::RIGHT;

		break;
	}
}

HollowKnight::~HollowKnight()
{
}
