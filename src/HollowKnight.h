#pragma once
#include <SDL.h>
#include "Spritesheet.h"
#include <iostream>
#include "Physics.h"

class HollowKnight : public Object
{
enum class Direction
{
	NONE, UP, DOWN, LEFT, RIGHT
};

private:
	Spritesheet image;
	SDL_Rect m_Position;
	double m_x, m_y;

	double m_MovingRight;

	Direction m_Direction;
public:
	HollowKnight();
	~HollowKnight();

	void update(double delta_time) override;
	void draw(SDL_Surface* surface) override;
	void handle_events(SDL_Event const& event) override;

};

