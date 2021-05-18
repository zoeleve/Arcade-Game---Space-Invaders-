#pragma once

#include <set>

#include "GameObject.h"
#include "GameStatus.h"

using namespace std;

class SpaceInvadersGame
{
	float lastime;
	int next_enemy_type;							// To epomeno eidos tou exthrou
	GameStatus* status;

	set<GameObject*> set_with_objects;				// Set gia na exei monadika kai taxonimimena stoixeia

public:

	SpaceInvadersGame();

	void init();

	// Apeikonizei ola ta antikeimena
	void draw_objects();

	// Update ola ta antikeimena
	void update_objects();

	// Elegxei oles tis sygrouseis
	void collision_test();

	// Vazei to antikeimeno object sto set me ta GameObject
	void add_object(GameObject *object);

	// Wste na auxanetai to skor ana 1,2 h 5
	void score_up();
	void score_double_up();
	void score_pentuple_up();

	// Wste na meiwnontai oi zwes
	void lifes_down();

	~SpaceInvadersGame();
};

