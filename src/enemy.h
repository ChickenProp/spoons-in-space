#ifndef GW_ENEMY_H
#define GW_ENEMY_H

#include "includes.h"
#include "entity.h"

class Bullet;

class Enemy : public Entity {
public:
	typedef Entity super;

	Enemy();

	int health;
	int ammoCount;

	int score;

	sf::Clock deadClock;
	float corpseLife;
	void die();

	virtual void hitByBullet(Bullet *bullet);

	virtual void update();
	virtual void render();
};

#endif
