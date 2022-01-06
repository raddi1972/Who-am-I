#pragma once
#include "Object.h"
#include "Spritesheet.h"
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
struct Timer {
    std::chrono::steady_clock::time_point start;
	std::chrono::steady_clock::time_point end;
	int getTimeElapsed()
	{
		int elapsed_time = int (std::chrono::duration_cast <std::chrono::seconds> (end - start).count());
		return elapsed_time;
	}
};

class Health: public Object
{
public:
	Health();
	~Health() {}

	void update(double delta_time) override;
	void handle_events(SDL_Event const& e) {}
	void draw(SDL_Surface* surface, int x, int y) override;
	bool isGravity() override { return false; }
	bool isCollideable() const { return false; }
	void increaseHealth();
	int decreaseHealth();
	int getHealth();
	bool flag;

	private:
		Spritesheet healthDisplay;
		SDL_Rect m_position;
		int currentHealth;
		int autoHealthIncrDuration;
		Timer t;
};

