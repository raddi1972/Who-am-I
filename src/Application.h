#pragma once
#include "Core.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_timer.h>


class Application
{
public:
	Application();
	~Application();

	void update();
	void draw();

private:
	SDL_Window* m_Window;
	SDL_Surface* m_Surface;
	SDL_Event m_WindowEvent;

};

