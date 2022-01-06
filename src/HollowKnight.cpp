#include "HollowKnight.h"

HollowKnight::HollowKnight(Health *ho, NDCounter *ScoreCounter)
	: walker("walker_inv.bmp", 1, 9), walker_inv("walker.bmp", 1, 9), jumper("jumper.bmp", 1, 12), jumper_inv("jumper_inv.bmp", 1, 12), attacker("attacker.bmp", 1, 6), attacker_inv("attacker_inv.bmp", 1, 6), Object({500 - 42, 400 - 42}, {0, 0}, 0.15, 84, 84, 1)
{
	score = 0;
	health = ho; //Pointer to the health indicator object is being set
	scoreCounter = ScoreCounter;
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

	attacked.push_back(std::pair<int, int>(0, 0));
	attacked.push_back(std::pair<int, int>(1, 0));
	attacked.push_back(std::pair<int, int>(2, 0));	
	attacked.push_back(std::pair<int, int>(3, 0));
	attacked.push_back(std::pair<int, int>(4, 0));
	attacked.push_back(std::pair<int, int>(5, 0));

	timepassed = 0;
	defenceTimer = 0;
	isDefenceMode = false;
	current = 0;
}


void HollowKnight::update(double delta_time)
{
	timepassed += delta_time;
	if(isDefenceMode)
		defenceTimer += delta_time;
	if (defenceTimer >= 10 && isDefenceMode) {
		isDefenceMode = false;
		defenceTimer = 0;
	}
	attackTime += delta_time;
	if (attackTime >= 2.5 && isAttackMode) {
		if(att)
			delete att;
		att = nullptr;
		isAttackMode = false;
	}

	
	if (att)
		att->update(delta_time);
	if (isAttackMode) {
		if (isFacingRight) {
			if (attackTime <= 0.4) {
				attacker.selectSprite(attacked[0].first, attacked[0].second);
			}
			else if (attackTime <= 0.8) {
				attacker.selectSprite(attacked[1].first, attacked[1].second);
			}
			else if (attackTime <= 1.2) {
				attacker.selectSprite(attacked[2].first, attacked[2].second);
			}
			else if (attackTime <= 1.6) {
				attacker.selectSprite(attacked[3].first, attacked[3].second);
			}
			else if (attackTime <= 2.0) {
				attacker.selectSprite(attacked[4].first, attacked[4].second);
			}
			else if (attackTime <= 2.4) {
				attacker.selectSprite(attacked[5].first, attacked[5].second);
			}
		}
		else {
			if (attackTime <= 0.4) {
				attacker_inv.selectSprite(attacked[0].first, attacked[0].second);
			}
			else if (attackTime <= 0.8) {
				attacker_inv.selectSprite(attacked[1].first, attacked[1].second);
			}
			else if (attackTime <= 1.2) {
				attacker_inv.selectSprite(attacked[2].first, attacked[2].second);
			}
			else if (attackTime <= 1.6) {
				attacker_inv.selectSprite(attacked[3].first, attacked[3].second);
			}
			else if (attackTime <= 2.0) {
				attacker_inv.selectSprite(attacked[4].first, attacked[4].second);
			}
			else if (attackTime <= 2.4) {
				attacker_inv.selectSprite(attacked[5].first, attacked[5].second);
			}
		}
	}

	if (vel.y <= 0.25 && vel.y >= -0.25) {
		if (vel.x <= 15 && vel.x >= 3 && timepassed > 0.5) {
			w++;
			w %= walk.size();
			walker.selectSprite(walk[w].first, walk[w].second);
			timepassed = 0;
			current = 0;
			isFacingRight = true;
		}
		else if (vel.x <= 60 && vel.x > 15 && timepassed > 0.5) {
			r++;
			r %= run.size();
			walker.selectSprite(run[r].first, run[r].second);
			timepassed = 0;
			current = 0;
			isFacingRight = true;
		}
		if (vel.x < 3 && timepassed > 0.5 && current == 0 && isFacingRight) {
			walker.selectSprite(0, 0);
			current = 0;
		}

		if (vel.x >= -15 && vel.x <= -3 && timepassed > 0.5) {
			w++;
			w %= walk.size();
			walker_inv.selectSprite(8 - walk[w].first, walk[w].second);
			timepassed = 0;
			current = 1;
			isFacingRight = false;
		}
		else if (vel.x >= -60 && vel.x < -15 && timepassed > 0.5) {
			r++;
			r %= run.size();
			walker_inv.selectSprite(8 -run[r].first, run[r].second);
			timepassed = 0;
			current = 1;
			isFacingRight = false;
		}
		if (vel.x > -3 && vel.x < 0 && timepassed > 0.5 && !isFacingRight) {
			walker_inv.selectSprite(8, 0);
		}
	}
	else {
		if (vel.x > 0) {
			if (vel.y < 0 && vel.y >= -10) {
				jumper.selectSprite(jump[2].first, jump[2].second);
				current = 2;
				isFacingRight = true;
			}
			else if (vel.y < -10 && vel.y >= -20)
			{
				jumper.selectSprite(jump[1].first, jump[1].second);
				current = 2;
				isFacingRight = true;
			}
			else if(vel.y < -20 && vel.y >= -50 ) {
				jumper.selectSprite(jump[0].first, jump[0].second);
				current = 2;
				isFacingRight = true;
			}
			else if (vel.y < -20 && vel.y >= -50) {
				jumper.selectSprite(1, 0);
				current = 2;
				isFacingRight = true;
			}
			else if (vel.y < -50) {
				jumper.selectSprite(0, 0);
				current = 2;
				isFacingRight = true;
			}
			else if (vel.y > 0 && vel.y <= 10) {
				jumper.selectSprite(fJump[2].first, fJump[2].second);
				current = 2;
				isFacingRight = true;
			}
			else if (vel.y > 10 && vel.y <= 20) {
				jumper.selectSprite(fJump[1].first, fJump[1].second);
				current = 2;
				isFacingRight = true;
			}
			else if (vel.y > 20) {
				jumper.selectSprite(fJump[0].first, fJump[0].second);
				current = 2;
				isFacingRight = true;
			}
		}
		else {
			if (vel.y < 0 && vel.y >= -10) {
				jumper_inv.selectSprite(11 - jump[2].first, jump[2].second);
				current = 3;
				isFacingRight = false;

			}
			else if (vel.y < -10 && vel.y >= -20)
			{
			jumper_inv.selectSprite(11 - jump[1].first, jump[1].second);
			current = 3;
			isFacingRight = false;
			}
			else if (vel.y < -20 && vel.y >= -50) {
			jumper_inv.selectSprite(11 - jump[0].first, jump[0].second);
			current = 3;
			isFacingRight = false;
			}
			else if (vel.y < -20 && vel.y >= -50) {
			jumper_inv.selectSprite(11 - 1, 0);
			current = 3;
			isFacingRight = false;
			}
			else if (vel.y < -50) {
			jumper_inv.selectSprite(11 - 0, 0);
			current = 3;
			isFacingRight = false;
			}
			else if (vel.y > 0 && vel.y <= 10) {
			jumper_inv.selectSprite(11 - fJump[2].first, fJump[2].second);
			current = 3;
			isFacingRight = false;
			}
			else if (vel.y > 10 && vel.y <= 20) {
			jumper_inv.selectSprite(11 - fJump[1].first, fJump[1].second);
			current = 3;
			isFacingRight = false;
			}
			else if (vel.y > 20) {
			jumper_inv.selectSprite(11 - fJump[0].first, fJump[0].second);
			current = 3;
			isFacingRight = false;
			}
		}
	}
}

void HollowKnight::draw(SDL_Surface* surface, int x, int y)
{
	m_Position.x = pos.x - getLength() / 2;
	m_Position.y = pos.y - getBredth()/2;
	if (att) att->draw(surface, 0, 0);

	if (isAttackMode) {
		if (isFacingRight)
			attacker.drawSelectedSprite(surface, &m_Position);
		else
			attacker_inv.drawSelectedSprite(surface, &m_Position);
		return;
	}
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
				vel.y = -50;
		}

		if (keys[SDL_SCANCODE_E]) {
			if (!isAttackMode) {
				attack();
			}
		}

		if (keys[SDL_SCANCODE_A] == 1) {
			if (vel.x > 0) {
				vel.x = 0;
			}
			if (vel.x >= -25)
				vel.x += -10;
		}
		if (keys[SDL_SCANCODE_D] == 1) {
			if (vel.x < 0) {
				vel.x = 0;
			}
			if (vel.x <= 25)
				vel.x += 10;
		}

		break;
	}
}



void HollowKnight::attack()
{
	isAttackMode = true;
	attackTime = 0;
	if (isFacingRight) {
		att = new Attack({ pos.x + getLength() / 2, pos.y });
		 
	}
	else {
		att = new Attack({ pos.x - (getLength() / 2), pos.y });
	}
}



void HollowKnight::reduceHealth()
{
	if (!isDefenceMode) {
		health->decreaseHealth();
		isDefenceMode = true;
	}

}

Attack* HollowKnight::getAttack()
{
	return att;
}

void HollowKnight::setAttack()
{
	att = nullptr;
}

void HollowKnight::increaseScore() {
	scoreCounter->increaseCount();
	score++;
}

Health * HollowKnight::getHealth()
{
	return health;
}

int HollowKnight::getScore()
{
	return score;
}

HollowKnight::~HollowKnight()
{
}
