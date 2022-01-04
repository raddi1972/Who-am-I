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
	Spritesheet walker, walker_inv, jumper, jumper_inv;
	SDL_Rect m_Position;
	double m_x, m_y;

	double m_MovingRight;

	std::vector<std::pair<int, int>> walk; int w;
	std::vector<std::pair<int, int>> run; int r;
	std::vector<std::pair<int, int>> jump; int j;
	std::vector<std::pair<int, int>> fJump; int f;

	int current;

	double timepassed;
	

	Direction m_Direction;

	Object *health; //Pointer to the health indicator object
	Object *scoreCounter; //Pointer to the counter that displays the player's score
public:
	HollowKnight(Object *ho, Object *ScoreCounter);
	~HollowKnight();

	void update(double delta_time) override;
	void draw(SDL_Surface* surface, int x, int y) override;
	void handle_events(SDL_Event const& event) override;
	bool isGravity() override { return true; }
	bool isCollideable() const { return true; }
};

