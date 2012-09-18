#include "enemy.h"
#include "player.h"
#include "bullet.h"
#include "enemy-manager.h"
#include "globals.h"
#include "game.h"
#include "sound.h"

Enemy::Enemy ()
	: deadClock(),
	  health(1) // default
{}

void Enemy::die() {
	markTrash();
	deadClock.Reset();

	if (G::player())
		G::player()->score += score;

	G::enemyMgr()->enemyDied(this);
	Sound::play(Sound::enemyKill);
}

void Enemy::hitByBullet (Bullet *bullet) {
	super::hitByBullet(bullet);
	G::gameScreen->addParticles(pos, bullet->vel / 10, 50);
	health--;
	if (health <= 0)
		die();
	else
	Sound::play(Sound::enemyHit);
}

void Enemy::update() {
	super::update();

	if (dead && deadClock.GetElapsedTime() > corpseLife) {
		markTrash();
	}

	if (! G::player())
		pos += vel;

	G::gameScreen->addParticles(pos, -vel, 1, 100, 5000);
}

void Enemy::render() {
	// Make it really die before hitting 0 visibility, or we won't be able
	// to see it for some of its dead-time.
	if (dead) {
		float alpha = 255 - (200*deadClock.GetElapsedTime()/corpseLife);
		sprite.SetColor(sf::Color(128, 128, 128, alpha));
	}		                          

	super::render();
}
