#pragma once
#include "Object.h"
#include "Spritesheet.h"
#include "SDCounter.h"

class NDCounter: public Object
{
public:
	NDCounter(Vec2D pos);
	~NDCounter() {}
	void update(double delta_time) {}
	void handle_events(SDL_Event const& e) {}
	void draw(SDL_Surface* surface, int x, int y) override;
	bool isGravity() override { return false; }
	bool isCollideable() const { return false; }
	void increaseCount();
	void decreaseCount();

	private:
		std::vector<SDCounter *> digits;
		double SDw;
		Spritesheet score;
		SDL_Rect m_position;
};
