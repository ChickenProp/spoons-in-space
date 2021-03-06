#ifndef GW_PARTICLE_H
#define GW_PARTICLE_H

#include "includes.h"

class Particle {
public:
	ph::vec2f pos;
	ph::vec2f vel;
	
	GLushort r;
	GLushort g;
	GLushort b;
	GLushort a;

	GLushort drop;

	char unused[14]; //pad to 32 bytes

	Particle (ph::vec2f pos, ph::vec2f vel, GLushort drop = 255)
		: pos(pos), vel(vel), r(65535), g(65535), b(65535), a(65535),
		drop(drop)
	{}

	void update () { // assume 60fps for speed. Probably unnecessary.
		pos += vel;
		if (a >= drop)
			a -= drop;
	}
};

#endif
