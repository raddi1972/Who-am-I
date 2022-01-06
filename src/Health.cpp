#include "Health.h"

Health::Health() : healthDisplay("Health_indicator_sprite.bmp", 1, 6), Object({540,53}, {0,0}, 1, 186, 82, 0)
{
	currentHealth = 5;
	healthDisplay.selectSprite(currentHealth, 0);
	autoHealthIncrDuration = 20;
	m_position.x = 0;
	m_position.y = 0;
	m_position.w = getLength();
	m_position.h = getBredth();
	flag = true;
	t.start = std::chrono::steady_clock::now();
}

void Health::draw(SDL_Surface* surface, int x, int y)
{
	m_position.x = pos.x - m_position.w/2;
	m_position.y = pos.y - m_position.h/2;
	healthDisplay.drawSelectedSprite(surface, &m_position);
}

void Health::update(double delta_time)
{
	t.end = std::chrono::steady_clock::now();
	if(t.getTimeElapsed() == autoHealthIncrDuration)
	{
		this->increaseHealth();
		t.start = std::chrono::steady_clock::now();
	}
}

void Health::increaseHealth()
{
	if(currentHealth < 5 && flag)
	{
		currentHealth++;
	}
	healthDisplay.selectSprite(currentHealth, 0);
}

int Health::decreaseHealth() //To be called when player gets hit by enemies. Returns the current health level of the player
{
	if(currentHealth > 0)
	{
		currentHealth--;
	}
	healthDisplay.selectSprite(currentHealth, 0);
	return currentHealth; //currentHealth varies from 0 to 5
}

int Health::getHealth()
{
	return currentHealth;
}