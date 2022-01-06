#pragma once
#include <fstream>
#include "Core.h"
#include "HollowKnight.h"
#include "Ledge.h"
#include "Map.h"
#include "Health.h"
#include "NDCounter.h"
#include "Crawlid.h"
#include "ShootingEnemy.h"
#include "EnemyController.h"
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
	std::vector<Object *> enemies;
	std::vector<Object*> drawables;
 	HollowKnight* hk;
	EnemyController *ec;
	Map pakka;
	Map gameOver;
	std::string filename;
	int filecount;

	SDL_Window* m_Window;
	SDL_Surface* m_Surface;
	SDL_Event m_WindowEvent;

	Physics ph;

};

