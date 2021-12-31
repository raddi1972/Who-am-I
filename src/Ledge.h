#pragma once
#include "Object.h"
class Ledge :
    public Object
{
public:
	Ledge(Vec2D pos, Vec2D vel, double length, double breadth);

	void update(double delta_time) {}
	void handle_events(SDL_Event const& e) {}
	void draw(SDL_Surface* surface) {}
	bool isGravity() override { return false; }

};

