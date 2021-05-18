#pragma once

#include "GameObject.h"

#include "SpaceInvadersGame.h"

class SpaceShip : public GameObject
{
protected:

	float lastime;
	SpaceInvadersGame & game;

public:

	SpaceShip(SpaceInvadersGame& g, float x, float y, float r);

	void draw();
	void update();
	void collision_with_alien(GameObject* object);
};

