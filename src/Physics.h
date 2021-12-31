#pragma once

struct Vec2D {
	double X, Y;
};

struct State
{
	Vec2D position, velocity, acceleration;
};

class Physics
{
public:
	// Functions for 2D linear motion
	void getPosition(State &state, double t); // returns updated position and velocity
	void applyForce(State &state, double force);
	void applyImpulse(State& state, double impulse);
	// void CollisionDetector

};

//
//struct = { posx, posy, velX, velY,, accX, accY } (All double)
//
//	Force -> acc
//	Impulse -> Velocity
//	Gravity
//
//	Collision Detection -> Collision Handling -> Collision Reaction
