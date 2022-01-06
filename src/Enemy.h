#pragma once
#include "Object.h"
class Enemy :
    public Object
{

public:
	int health;
    Enemy(Vec2D pos, double e, double length, double bredth, double mass, int health);
    ~Enemy();

	virtual void update(double delta_time) = 0;
	void handle_events(SDL_Event const& e);
	virtual void draw(SDL_Surface* surface, int x, int y) = 0;
	bool isGravity() { return true; }
	bool isCollideable() const { return true; };
	void reduceHealth();
};

