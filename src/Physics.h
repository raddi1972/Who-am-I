#pragma once
#include <iostream>
#include "Object.h"
#include "HollowKnight.h"

class Physics
{
	double m_fric, m_grav;

	// Dash, move (friction -> opposite acceleration till velocity is there to stop the character even in air)
public:

	Physics();
	double update(double dt, std::vector<Object*>, Object* hk, std::vector<Object*>);
	double move(double vx);
	double dash();

	bool detectCollision(const Object& obj1, const Object& obj2);
	void collisionHandler(Object & obj1, Object& obj2);
	void resolveCollision(Object& obj1, Object& obj2, Vec2D normal, double pen);

};

