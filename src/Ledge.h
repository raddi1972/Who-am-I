#pragma once
#include "Object.h"
class Ledge :
    public Object
{
public:
	Ledge(Vec2D pos, Vec2D vel, double length, double breadth);
	~Ledge() override {}

	void update(double delta_time) {}
	void handle_events(SDL_Event const& e) {}
	void draw(SDL_Surface* surface, int x, int y) override;
	bool isGravity() override { return false; }
	bool isCollideable() const { return false; }

};

