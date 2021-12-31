#include "Object.h"

double Vec2D::getMag() {
	return sqrt(x * x + y * y);
}

void Vec2D::normalize() {
	x /= getMag();
	y /= getMag();
}

Object::Object(Vec2D pos, Vec2D vel, double e, double length, double breadth, double mass) {
	this->pos = pos;
	this->vel = vel;
	this->e = e;
	this->length = length;
	this->bredth = breadth;
	if (mass)
		this->invMass = 1 / mass;
	else
		this->invMass = 0;
}

std::vector<Vec2D> Object::getPoints() const
{
	std::vector<Vec2D> points;
	points.push_back({pos.x + length/2, pos.y + bredth/2});
	points.push_back({pos.x - length/2, pos.y + bredth/2});
	points.push_back({pos.x + length/2, pos.y - bredth/2});
	points.push_back({pos.x - length/2, pos.y - bredth/2});
	return points;
}
