#pragma once

#include "GameObject.h"
#include "Allien.h"
#include "SpaceInvadersGame.h"

// H sfaira pou rixnei to SpaceShip
class Shot : public GameObject
{
	float speed;				// Taxitita sfairas
	SpaceInvadersGame& game;	// Anafora sto SpaceInvadersGame

public:

	Shot(SpaceInvadersGame& g, float s, float x, float y, float r);

	void draw();
	void update();
	void collision_with_alien(GameObject* object);
};

