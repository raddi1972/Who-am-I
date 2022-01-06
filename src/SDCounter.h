#pragma once
#include "Object.h"
#include "Spritesheet.h"

class SDCounter: public Object
{
	public:
		SDCounter(Vec2D pos);
		~SDCounter() {}
	
		void update(double delta_time) {};
		void handle_events(SDL_Event const& e) {}
		void draw(SDL_Surface* surface, int x, int y) override;
		bool isGravity() override { return false; }
		bool isCollideable() const { return false; }
		int increaseCount();
		int decreaseCount();
		int getCount();

	private:
		Spritesheet countDisplay;
		SDL_Rect m_position;
		int count;
};

