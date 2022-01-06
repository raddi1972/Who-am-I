#pragma once
#include "Enemy.h"
#include "Spritesheet.h"
class Crawlid :
    public Enemy
{
private:
	SDL_Rect m_Position;
	double timepassed;
	std::vector<std::pair<int, int>> walk; int w;
	Spritesheet walker, walker_inv;
public:
	bool isFacingRight;

	Crawlid(Vec2D pos, double length, double bredth);
	~Crawlid();

	void draw(SDL_Surface* surface, int x, int y) override;
	void update(double delta_time) override;


};

