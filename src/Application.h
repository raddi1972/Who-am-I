#pragma once
#include "Core.h"
#include "HollowKnight.h"
#include "Ledge.h"
#include "Map.h"
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
	
	std::vector<Object *> objs;
	HollowKnight* hk;
	Map pakka;

	SDL_Window* m_Window;
	SDL_Surface* m_Surface;
	SDL_Event m_WindowEvent;

	Physics ph;

};

