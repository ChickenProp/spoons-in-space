#include "e-cheese.h"
#include "includes.h"
#include "globals.h"
#include "bullet.h"
#include "game.h"
#include "player.h"

E_Cheese::E_Cheese (ph::vec2f _pos) {
	pos = _pos;
	radius = 8;
	score = 15;
	sprite.SetImage(G::Images::enemy_cheese);
	sprite.SetCenter(64, 64);
	sprite.Resize(20, 20);
}

void E_Cheese::update () {
	super::update();

	std::vector<Bullet*> bullets = G::gameScreen->bullets;
	Bullet *nearest = NULL;
	for(std::vector<Bullet*>::iterator it = bullets.begin();
	    it != bullets.end(); it++)
	{
		if (! *it)
			continue;

		if (!nearest)
			nearest = *it;

		if (pos.distance(nearest->pos) < pos.distance((*it)->pos))
			nearest = *it;
	}

	ph::vec2f dir;
	if (nearest && pos.distance(nearest->pos) < 300)
		dir = (pos - nearest->pos).normalize();
	else if (G::player())
		dir = (G::player()->pos - pos).normalize();
	else
		dir = ph::vec2f(0, 0);


	vel = accel_drag(dir, 150, 0.3);
	pos += vel;

	bounceOffWalls(0.8);
}
