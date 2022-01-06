#include "Enemy.h"


Enemy::Enemy(Vec2D pos, double e, double length, double bredth, double mass, int health)
	: Object(pos, {0, 0}, e, length, bredth, mass), health(health)
{
}

Enemy::~Enemy()
{
}

void Enemy::handle_events(SDL_Event const& e)
{
	// does not handle events, as this is non playable character
}

void Enemy::reduceHealth()
{
	health -= 1;
}

