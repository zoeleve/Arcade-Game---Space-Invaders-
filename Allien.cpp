#include "Allien.h"

#include <string>

using namespace std;

Alien::Alien(float x, float y, float r):GameObject(x,y,r)
{
	life = 1;			// Oi aploi Alien exoun mia zwh
	speed = 0.5;		// Taxita 0.5
	Fx = Fy = 1.0;

	brush.texture = string(assets_path)+"alien.png";
}

void Alien::hit()
{
	if( life > 0 )
		life--;
}

void Alien::draw()
{
	// To apeikonizei an einai enargopoihmeno
	if (is_active == true)
		graphics::drawRect(position.x, position.y, radius, radius, brush);
}

void Alien::update()
{
	// An exei xtypithei apo sfaira
	if (life <= 0)
		is_active = false;

	// Paei pros ta katw
	position.y = position.y + speed*graphics::getDeltaTime()/10.0f;
}

bool Alien::isLive()
{
	if (life == 0)
		return true;
	else
		return false;
}

/* --- OctapusAlien ----*/
OctapusAlien::OctapusAlien(float x, float y) : Alien(x, y, 30)
{
	life = 2;			// Oi aploi OctapusAlien exoun 2 zwes
	brush.texture = string(assets_path) + "octopus.png";
}

/* --- SciFiAlien ----*/
SciFiAlien::SciFiAlien(float x, float y) : Alien(x, y, 40)
{
	life = 3;			// Oi aploi SciFiAlien exoun 3 zwes
	brush.texture = string(assets_path) + "scifi.png";
}