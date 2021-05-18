#include "SpaceShip.h"
#include "Allien.h"
#include "Shot.h"

SpaceShip::SpaceShip(SpaceInvadersGame& g, float x, float y, float r):GameObject(x,y,r), game(g)
{
	lastime = 0;

	// einonidio sto diastimoploio
	brush.texture = string(assets_path) + "spaceship.png";
}

void SpaceShip::draw()
{
	graphics::drawRect(position.x, position.y, radius, radius, brush);
}

void SpaceShip::update()
{
	float nowtime = graphics::getGlobalTime();

	// Wste na katalabei poio koumpi patithike
	if (graphics::getKeyState(graphics::SCANCODE_LEFT) == true)
	{
		position.x = position.x - 1 * graphics::getDeltaTime() / 2.0f;
	}
	else if (graphics::getKeyState(graphics::SCANCODE_RIGHT) == true)
	{
		position.x = position.x + 1 * graphics::getDeltaTime() / 2.0f;
	}

	// Wste na min vgei poly aristera alla oute kai polh dexia
	if (position.x - radius <= 0)
	{
		position.x = radius;
	}
	else if (position.x + radius >= canvas_width)
	{
		position.x = canvas_width-radius;
	}

	// Den mporei na rixnei synexia voles alla ana 500ms
	if (nowtime - lastime > 500)
	{
		// Wste na doume an pyrobolise kata twn Alien
		if (graphics::getKeyState(graphics::SCANCODE_SPACE) == true)
		{
			// Wste na ftiaxei mia nea voli kai na tin prosthesei sto paixnidi
			Shot* s = new Shot(game, 3.0, position.x, position.y, 10.0);

			game.add_object(s);
			lastime = nowtime;

			// Wste na paixei ixo
			graphics::playSound(string(assets_path) + "shot_sound.wav", 1.0f);
		}
	}
}

void SpaceShip::collision_with_alien(GameObject* object)
{
	// Wste na dei an einai typou Alien to GameObject
	Alien* alien = dynamic_cast<Alien*>(object);

	// an einai Alien, tote to alien apenergopoieitai kai meiwnetai mia zwh
	if (alien != nullptr)
	{
		float distance = sqrt( pow(position.x - object->getX(), 2) + pow(position.y - object->getY(), 2));

		if (distance < radius + object->getRadius())
		{
			alien->hit();
			game.lifes_down();
		}
	}
}
