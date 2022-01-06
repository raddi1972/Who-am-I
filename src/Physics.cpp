#include "Physics.h"

#define Log(x) std::cout << x << std::endl

Physics::Physics() {
	m_fric = 1;
	m_grav = 4; 
}


double getMax(std::vector<Vec2D> &vecs, double (*prop) (Vec2D)) {
	if (vecs.size() == 0)
		return -1;
	double max = prop(vecs[0]);
	for (auto v : vecs) {
		if (prop(v) > max)
			max = prop(v);
	}
	return max;
}


bool Physics::detectCollision(const Object& obj1, const Object& obj2) {

	std::vector<Vec2D> points1 = obj1.getPoints();
	std::vector<Vec2D> points2 = obj2.getPoints();

	if (!obj1.isCollideable() && !obj2.isCollideable())
		return false;

	// projections on X
	double p1XMax = getMax(points1, [](Vec2D v) -> double { return v.x; });
	double p1XMin = -getMax(points1, [](Vec2D v) -> double { return -v.x; });
	double p2XMax = getMax(points2, [](Vec2D v) -> double { return v.x; });
	double p2XMin = -getMax(points2, [](Vec2D v) -> double { return -v.x; });

	// projections on Y
	double p1YMax = getMax(points1, [](Vec2D v) -> double { return v.y; });
	double p1YMin = -getMax(points1, [](Vec2D v) -> double { return -v.y; });
	double p2YMax = getMax(points2, [](Vec2D v) -> double { return v.y; });
	double p2YMin = -getMax(points2, [](Vec2D v) -> double { return -v.y; });

	bool isSeparatedX = p2XMax < p1XMin || p1XMax < p2XMin;
	bool isSeparatedY = p2YMax < p1YMin || p1YMax < p2YMin;

	if ((isSeparatedX || isSeparatedY)) {
		return false;
	}

	return true;
}

void Physics::collisionHandler(Object& obj1, Object& obj2) {
	Vec2D i = { 1, 0 };
	Vec2D j = { 0, 1 };
	Vec2D normal;
	double pen;

	Vec2D n = obj2.getPos() - obj1.getPos();

	float x_overlap = obj1.getLength() / 2 + obj2.getLength() / 2 - abs(n * i);

	if (x_overlap > 0) {
		float y_overlap = obj1.getBredth() / 2 + obj2.getBredth() / 2 - abs(n * j);
		
		if (y_overlap > 0) {
			if (x_overlap < y_overlap) {
				if (n * i < 0) {
					normal = { -1, 0 };
				}
				else {
					normal = { 1, 0 };
				}
				pen = x_overlap;
			}
			else {
				if (n * j < 0) {
					normal = { 0, -1 };
				}
				else {
					normal = { 0, 1 };
				}
				pen = y_overlap;
			}
			resolveCollision(obj1, obj2, normal, pen);
			return;
		}
	}
}

void Physics::resolveCollision(Object& obj1, Object& obj2, Vec2D normal, double pen) {

	Vec2D rv = obj2.getVel() - obj1.getVel();

	double velTowardsNormal = rv * normal;

	if (velTowardsNormal > 0)
		return;
	float e = fmin(obj1.getE(), obj2.getE());
	float j = -(1 + e) * velTowardsNormal;
	j /= obj1.getInvMass() + obj2.getInvMass();

	Vec2D impulse = {j * normal.x, j * normal.y};
	obj1.setVel({ -impulse.x * obj1.getInvMass(), -impulse.y * obj1.getInvMass()});
	obj2.setVel({ impulse.x * obj2.getInvMass(), impulse.y * obj2.getInvMass() });

	const float percent = 0.8; // usually 20% to 80%
	Vec2D correction = normal * (pen / (obj1.getInvMass() + obj2.getInvMass())* percent);
	obj1.pos = obj1.pos - correction * obj1.getInvMass();
	obj2.pos = obj2.pos +  correction * obj2.getInvMass();
}

double Physics::update(double dt, std::vector<Object*> obj, Object* hk, std::vector<Object*> enemies)
{

	for (auto o : obj) {
		if (detectCollision(*o, *hk)) {
			std::cout << "collided" << std::endl;
			collisionHandler(*hk, *o);
		}
	}

	for (auto e : enemies) {
		for (auto o : obj) {
			if (detectCollision(*e, *o)) {
				std::cout << "Collided" << std::endl;
				collisionHandler(*e, *o);

			}
		}
	}

	for (auto e : enemies) {
		e->pos.x += e->vel.x * dt;
	}

	if ((hk->vel.x > 0 && m_fric > 0) 
		|| (hk->vel.x < 0 && m_fric < 0)) {
		m_fric = -m_fric;
	}

	if (hk->vel.x) {
		hk->pos.x += hk->vel.x * dt + (m_fric * dt * dt) / 2;
		hk->vel.x += m_fric * dt;
	}

	if ( (hk->vel.x + m_fric * dt < 0 && hk->vel.x > 0)
		|| (hk->vel.x + m_fric * dt > 0 && hk->vel.x < 0)) {
		hk->vel.x = 0;
	}

	if (hk->isGravity()) {
		hk->pos.y += hk->vel.y * dt + (m_grav * dt * dt) / 2;
		hk->vel.y += m_grav * dt;
	}

	for (auto e : enemies) {
		if (e->isGravity()) {
			e->pos.y += e->vel.y * dt + (m_grav * dt * dt) / 2;
			e->vel.y += m_grav * dt;
		}
	}

	return 0;
}
