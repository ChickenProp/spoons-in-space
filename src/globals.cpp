#include "globals.h"
#include "game.h"

sf::RenderWindow G::window;
const sf::Input &G::input = G::window.GetInput();

int G::framerate = 60;

Screen *G::curScreen = NULL;
Game *G::gameScreen = NULL;

sf::Image G::Images::backdrop;
sf::Image G::Images::player;
sf::Image G::Images::bullet;
sf::Image G::Images::glow;
sf::Image G::Images::enemy_circle;
sf::Image G::Images::enemy_triangle;
sf::Image G::Images::enemy_square;
sf::Image G::Images::enemy_cheese;
sf::Image G::Images::spoon;

Player *G::player () {
	if (!gameScreen)
		return NULL;
	return gameScreen->player;
}

EnemyMgr *G::enemyMgr () {
	if (!gameScreen)
		return NULL;
	return gameScreen->enemies;
}

bool G::loadImages () {
	bool succ = true;

	succ = succ && G::Images::backdrop.LoadFromFile("media/space.png");
	succ = succ && G::Images::player.LoadFromFile("media/astronaut.png");
	succ = succ && G::Images::bullet.LoadFromFile("media/bullet.png");
	succ = succ && G::Images::glow.LoadFromFile("media/glow.tga");
	succ = succ && G::Images::enemy_circle.LoadFromFile("media/pea.png");
	succ = succ && G::Images::enemy_triangle.LoadFromFile("media/enemy-triangle.tga");
	succ = succ && G::Images::enemy_square.LoadFromFile("media/enemy-square.tga");
	succ = succ && G::Images::enemy_cheese.LoadFromFile("media/cheese.png");
	succ = succ && G::Images::spoon.LoadFromFile("media/spoon.png");

	return succ;
}
