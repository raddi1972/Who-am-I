#pragma once
#include <SDL.h>
#include "Spritesheet.h"
#include <iostream>
#include "Physics.h"
#include "Health.h"
#include "Attack.h"
#include "NDCounter.h"

class HollowKnight : public Object
{
enum class Direction
{
	NONE, UP, DOWN, LEFT, RIGHT
};

private:
	Spritesheet walker, walker_inv, jumper, jumper_inv, attacker, attacker_inv;
	Attack* att;
	SDL_Rect m_Position;
	double m_x, m_y;

	double m_MovingRight;

	std::vector<std::pair<int, int>> walk; int w;
	std::vector<std::pair<int, int>> run; int r;
	std::vector<std::pair<int, int>> jump; int j;
	std::vector<std::pair<int, int>> fJump; int f;
	std::vector<std::pair<int, int>> attacked;

	int current;

	double timepassed;

	bool isAttackMode;
	double attackTime;

	Direction m_Direction;

	Health *health; //Pointer to the health indicator object
	NDCounter *scoreCounter; //Pointer to the counter that displays the player's score

	int score;
public:
	bool isFacingRight;
	bool isDefenceMode;
	double defenceTimer;

	HollowKnight(Health *ho, NDCounter *ScoreCounter);
	~HollowKnight();

	void update(double delta_time) override;
	void draw(SDL_Surface* surface, int x, int y) override;
	void handle_events(SDL_Event const& event) override;
	bool isGravity() override { return true; }
	bool isCollideable() const { return true; }
	void attack();

	void reduceHealth();
	Attack* getAttack();
	void setAttack();
	void increaseScore();
	Health* getHealth();
	int getScore();
};

