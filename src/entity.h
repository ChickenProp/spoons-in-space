#ifndef GW_ENTITY_H
#define GW_ENTITY_H

#include "includes.h"

class Bullet;

class Entity {
public:
	Entity();

	static int nextId;
	std::string id;
	void setId(std::string name);

	sf::Sprite sprite;
	float radius;

	ph::vec2f pos;
	ph::vec2f vel;
	float angle;

	bool dead;
	bool trash;
	void markTrash();
	static bool deadPtr(Entity *ptr);

	virtual void update();
	virtual void render();

	virtual bool bounceOffWalls(float restitution, float *bounceVel = NULL);

	virtual void checkBulletCollisions(const std::vector<Bullet*> &bullets);
	virtual void hitByBullet(Bullet *bullet);

	ph::vec2f accel_drag(ph::vec2f dir, float maxSpeed, float timeToHalf);

	bool colliding(Entity *other);
};

#endif
