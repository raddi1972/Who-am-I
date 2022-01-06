#pragma once
#include <SDL.h>
#include "Spritesheet.h"
#include <iostream>
#include "Physics.h"
#include "Enemy.h"

class CannonFire : public Enemy
{

private:
	Spritesheet propagation, burst;
	SDL_Rect m_position;
	double timepassed;
    int currentSpriteSheet;
    Vec2D initialVel;
    int count;
    bool destroyed;
	bool collided;
	
public:
	CannonFire(Vec2D p, Vec2D v);
	~CannonFire();

	void update(double delta_time) {}
    int fire(double delta_time);
	void draw(SDL_Surface* surface, int x, int y) override;
	void handle_events(SDL_Event const& event) {}
	bool isGravity() override { return false; }
	bool isCollideable() const { return true; }
	void informCollision();
};