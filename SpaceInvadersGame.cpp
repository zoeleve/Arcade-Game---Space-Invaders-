#include "SpaceInvadersGame.h"
#include "SpaceShip.h"
#include "Allien.h"

#include <random>
#include <ctime>
#include "Shot.h"

using namespace std;

SpaceInvadersGame::SpaceInvadersGame()
{
	init();
}

void SpaceInvadersGame::init()
{
	lastime = 0;

	srand( time(nullptr) );

	status = new GameStatus();

	set_with_objects.insert( new SpaceShip(*this, canvas_width/2, canvas_height-70, 50 ));
	set_with_objects.insert( status );

	next_enemy_type = 1;

	for (int i = 0; i < 10; i++)
	{
		set_with_objects.insert(new Alien(100 +i * 100, 70, 20));
	}
}

void SpaceInvadersGame::draw_objects()
{
	for (auto object : set_with_objects)
	{
		object->draw();
	}
}

void SpaceInvadersGame::update_objects()
{
	for (auto object : set_with_objects )
	{
		object->update();
	}

	// Vriskei poia antikeimena einai ektos camva h anerga kai ta svinei
	for (auto object : set_with_objects)
	{
		if (object->is_out() == true)
		{
			delete object;
			set_with_objects.erase(object);
			break;
		}
	}

	// Wste na elexei gia sigrouseis
	collision_test();

	// Prosthetei mia nea grammi exthrwn an exoun perasei 3''
	float nowtime = graphics::getGlobalTime();

	if (nowtime - lastime < 3000)
	{
		return;
	}
	lastime = nowtime;

	if (next_enemy_type == 1)
	{
		for (int i = 0; i < 10; i++)
		{
			set_with_objects.insert(new Alien(100+i * 100, 70, 20));
		}
		next_enemy_type = 2;
	}
	else if (next_enemy_type == 2)
	{
		for (int i = 0; i < 10; i++)
		{
			set_with_objects.insert(new OctapusAlien(200+i * 100, 70));
		}
		next_enemy_type = 3;
	}
	else if (next_enemy_type == 3)
	{
		for (int i = 0; i < 10; i++)
		{
			set_with_objects.insert(new SciFiAlien(150+i * 100, 70));
		}
		next_enemy_type = 1;
	}
}


void SpaceInvadersGame::collision_test()
{
	Shot* shot;
	SpaceShip* spaceship;

	for (auto object : set_with_objects)
	{
		spaceship = dynamic_cast<SpaceShip*>(object);
		shot = dynamic_cast<Shot*>(object);

		if (spaceship != nullptr)				// an to object einai Spaceship
		{
			for (auto other_object : set_with_objects)
			{
				spaceship->collision_with_alien(other_object);
			}
		}
		else if (shot != nullptr)				// an to object einai Shot
		{
			for (auto other_object : set_with_objects)
			{
				shot->collision_with_alien(other_object);
			}
		}
	}
}

void SpaceInvadersGame::add_object(GameObject* object)
{
	set_with_objects.insert(object);
}

void SpaceInvadersGame::score_up()
{
	status->score_up();
}

void SpaceInvadersGame::score_double_up()
{
	status->score_double_up();
}

void SpaceInvadersGame::score_pentuple_up()
{
	status->score_pentuple_up();
}

void SpaceInvadersGame::lifes_down()
{
	status->lifes_down();
}

SpaceInvadersGame::~SpaceInvadersGame()
{
	// Svinei ola ta GameObjects apo to set
	for (auto object : set_with_objects)
	{
		delete object;
	}

	set_with_objects.clear();
}
