#include "HollowKnight.h"

HollowKnight::HollowKnight()
	: walker("walker_inv.bmp", 1, 9), walker_inv("walker.bmp", 1, 9), jumper("jumper.bmp", 1, 12), jumper_inv("jumper_inv.bmp", 1, 12), Object({500 - 42, 400 - 42}, {0, 0}, 0.15, 84, 84, 1)
{
	walker.selectSprite(0, 0);
	walker_inv.selectSprite(0, 0);
	jumper.selectSprite(0, 0);
	jumper_inv.selectSprite(0, 0);

	m_Position.x = 0;
	m_Position.y = 0;
	m_Position.w = getLength();
	m_Position.h = getBredth();

	m_x = 0.0;
	m_y = 0.0;

	m_MovingRight = 0;

	w = 0; r = 0; j = 0;
	walk.push_back(std::pair<int, int>(1, 0));
	walk.push_back(std::pair<int, int>(2, 0));
	walk.push_back(std::pair<int, int>(3, 0));
	walk.push_back(std::pair<int, int>(4, 0));

	run.push_back(std::pair<int, int>(5, 0));
	run.push_back(std::pair<int, int>(6, 0));
	run.push_back(std::pair<int, int>(7, 0));
	run.push_back(std::pair<int, int>(8, 0));

	jump.push_back(std::pair<int, int>(2, 0));
	jump.push_back(std::pair<int, int>(3, 0));
	jump.push_back(std::pair<int, int>(4, 0));

	fJump.push_back(std::pair<int, int>(5, 0));
	fJump.push_back(std::pair<int, int>(6, 0));
	fJump.push_back(std::pair<int, int>(7, 0));

	timepassed = 0;
	current = 0;
}


void HollowKnight::update(double delta_time)
{
	timepassed += delta_time;
	if (vel.y <= 0.25 && vel.y >= -0.25) {
		if (vel.x <= 15 && vel.x >= 3 && timepassed > 0.5) {
			w++;
			w %= walk.size();
			walker.selectSprite(walk[w].first, walk[w].second);
			timepassed = 0;
			current = 0;
		}
		else if (vel.x <= 60 && vel.x > 15 && timepassed > 0.5) {
			r++;
			r %= run.size();
			walker.selectSprite(run[r].first, run[r].second);
			timepassed = 0;
			current = 0;

		}
		if (vel.x < 3 && timepassed > 0.5 && current == 0) {
			walker.selectSprite(0, 0);
			current = 0;

		}

		if (vel.x >= -15 && vel.x <= -3 && timepassed > 0.5) {
			w++;
			w %= walk.size();
			walker_inv.selectSprite(8 - walk[w].first, walk[w].second);
			timepassed = 0;
			current = 1;

		}
		else if (vel.x >= -60 && vel.x < -15 && timepassed > 0.5) {
			r++;
			r %= run.size();
			walker_inv.selectSprite(8 -run[r].first, run[r].second);
			timepassed = 0;
			current = 1;
		}
		if (vel.x > -3 && vel.x < 0 && timepassed > 0.5 && current == 1) {
			walker_inv.selectSprite(8, 0);
		}
	}
	else {
		if (vel.x > 0) {
			if (vel.y < 0 && vel.y >= -10) {
				jumper.selectSprite(jump[2].first, jump[2].second);
				current = 2;
			}
			else if (vel.y < -10 && vel.y >= -20)
			{
				jumper.selectSprite(jump[1].first, jump[1].second);
				current = 2;
			}
			else if(vel.y < -20 && vel.y >= -50 ) {
				jumper.selectSprite(jump[0].first, jump[0].second);
				current = 2;
			}
			else if (vel.y < -20 && vel.y >= -50) {
				jumper.selectSprite(1, 0);
				current = 2;
			}
			else if (vel.y < -50) {
				jumper.selectSprite(0, 0);
				current = 2;
			}
			else if (vel.y > 0 && vel.y <= 10) {
				jumper.selectSprite(fJump[2].first, fJump[2].second);
				current = 2;
			}
			else if (vel.y > 10 && vel.y <= 20) {
				jumper.selectSprite(fJump[1].first, fJump[1].second);
				current = 2;
			}
			else if (vel.y > 20) {
				jumper.selectSprite(fJump[0].first, fJump[0].second);
				current = 2;
			}
		}
		else {
			if (vel.y < 0 && vel.y >= -10) {
				jumper_inv.selectSprite(11 - jump[2].first, jump[2].second);
				current = 3;
			}
			else if (vel.y < -10 && vel.y >= -20)
			{
			jumper_inv.selectSprite(11 - jump[1].first, jump[1].second);
			current = 3;
			}
			else if (vel.y < -20 && vel.y >= -50) {
			jumper_inv.selectSprite(11 - jump[0].first, jump[0].second);
			current = 3;
			}
			else if (vel.y < -20 && vel.y >= -50) {
			jumper_inv.selectSprite(11 - 1, 0);
			current = 3;
			}
			else if (vel.y < -50) {
			jumper_inv.selectSprite(11 - 0, 0);
			current = 3;
			}
			else if (vel.y > 0 && vel.y <= 10) {
			jumper_inv.selectSprite(11 - fJump[2].first, fJump[2].second);
			current = 3;
			}
			else if (vel.y > 10 && vel.y <= 20) {
			jumper_inv.selectSprite(11 - fJump[1].first, fJump[1].second);
			current = 3;
			}
			else if (vel.y > 20) {
			jumper_inv.selectSprite(11 - fJump[0].first, fJump[0].second);
			current = 3;
			}
		}
	}
}

void HollowKnight::draw(SDL_Surface* surface, int x, int y)
{
	if (pos.x <= 418) __debugbreak;
	m_Position.x = pos.x - 42;
	m_Position.y = pos.y - 42;
	if (current == 0) {
		walker.drawSelectedSprite(surface, &m_Position);
	}
	else if (current == 1) {
		walker_inv.drawSelectedSprite(surface, &m_Position);
	}
	else if (current == 2) {
		jumper.drawSelectedSprite(surface, &m_Position);
	}
	else if (current == 3) {
		jumper_inv.drawSelectedSprite(surface, &m_Position);
	}
}

void HollowKnight::handle_events(SDL_Event const& e)
{
	switch (e.type)
	{
	case SDL_KEYDOWN:
		Uint8 const* keys = SDL_GetKeyboardState(nullptr);

		if (keys[SDL_SCANCODE_SPACE] == 1) {
			if (vel.y >= 60 || (vel.y >= -1 && vel.y <= 1))
				vel.y = -70;
		}
		if (keys[SDL_SCANCODE_A] == 1) {
			if (vel.x > 0) {
				vel.x = 0;
			}
			if (vel.x >= -30)
				vel.x += -20;
		}
		if (keys[SDL_SCANCODE_D] == 1) {
			if (vel.x < 0) {
				vel.x = 0;
			}
			if (vel.x <= 30)
				vel.x += 20;
		}

		break;
	}
}

HollowKnight::~HollowKnight()
{
}
