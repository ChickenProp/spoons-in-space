#ifndef GW_E_CHEESE
#define GW_E_CHEESE

#include "includes.h"
#include "enemy.h"

class E_Cheese : public Enemy {
public:
	typedef Enemy super;

	E_Cheese(ph::vec2f pos);

	void update();
};

#endif
