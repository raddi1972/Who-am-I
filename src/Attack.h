#pragma once
#include "Object.h"
#include "Spritesheet.h"

class Attack :
    public Object
{

	Spritesheet sp;
	std::vector<std::pair<int, int>> attack; int a;
	double timepassed = 0;
	SDL_Rect m_Position;

public:
	Attack(Vec2D pos);
	~Attack();

	void update(double delta_time) override;
	void draw(SDL_Surface* surface, int x, int y) override;
	void handle_events(SDL_Event const& event) override {}
	bool isGravity() override { return true; }
	bool isCollideable() const { return true; }


};

