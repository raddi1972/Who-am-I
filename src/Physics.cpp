#include "Physics.h"


void Physics::getPosition(State &state, double t)
{
	// Assuming that, there is some acc, and some vel
	// using this we update position and vel values
	// Acceleration for most part is constant

	auto ax = state.acceleration.X;
	auto ay = state.acceleration.Y;

	auto vx = state.velocity.X + ax * t;
	auto vy = state.velocity.Y + ay * t;

	auto x = state.velocity.X * t + (ax * (t * t) )/ 2;
	auto y = state.velocity.Y * t + (ay * (t * t) )/ 2;

	state = { {x, y}, {vx, vy}, {ax, ay} };
}

void Physics::applyForce(State& state, double force)
{
}

void Physics::applyImpulse(State& state, double impulse)
{
}



