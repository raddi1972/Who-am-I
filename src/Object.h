#pragma once
#include <iostream>
#include <SDL.h>
#include <vector>

struct Vec2D {
	double x, y;

	double getMag();
	void normalize();

	Vec2D operator + (const Vec2D& vec) { return { x + vec.x, y + vec.y }; }

	double operator * (const Vec2D vec) { return x * vec.x + y * vec.y; }

	Vec2D operator - (const Vec2D vec) { return { x - vec.x, y - vec.y }; }

	Vec2D operator * (const double d) { return { x * d, y * d }; }

};

class Object
{
private:
	double e;
	double length, bredth;
	double invMass;

public:
	Vec2D pos; // Position of the centre
	Vec2D vel;

	Object(Vec2D pos, Vec2D vel, double e, double length, double breadth, double mass);
	virtual ~Object() {}

	// Pure virtual functions 
	virtual void update(double delta_time) = 0;
	virtual void handle_events(SDL_Event const& e) = 0;
	virtual void draw(SDL_Surface* surface, int x, int y) = 0;
	virtual bool isGravity() { return true; }
	virtual bool isCollideable() const = 0;

	std::vector<Vec2D> getPoints() const;
	Vec2D getPos() const { return pos; }
	Vec2D getVel() const { return vel; }
	double getE() const { return e; }
	double getLength() const { return length; }
	double getBredth() const { return bredth; };
	double getInvMass() const { return invMass; }
	void setVel(Vec2D v) { vel = vel + v; }
		 
};

