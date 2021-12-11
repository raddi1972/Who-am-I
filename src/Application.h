#pragma once
#include "Core.h"



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

	SDL_Surface* m_Image;
	SDL_Rect m_ImagePosition;

};

