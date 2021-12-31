#pragma once
#include "Core.h"
#include "HollowKnight.h"
#include <chrono>



class Application
{
public:
	Application();
	~Application();

	void update(double delta_time);
	void loop();
	void draw();

	std::chrono::steady_clock::time_point before;

private:
	
	HollowKnight hk;

	SDL_Window* m_Window;
	SDL_Surface* m_Surface;
	SDL_Event m_WindowEvent;

};

