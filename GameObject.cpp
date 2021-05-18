#include "GameObject.h"
#include "Configuration.h"

GameObject::GameObject(float x, float y, float r)
{
	is_active = true;
	position.x = x;
	position.y = y;
	radius = r;

	brush.fill_opacity = 1.0f;
	brush.outline_opacity = 0.0f;
}

bool GameObject::is_out()
{
	// an einai ektos tou kamva
	if (position.x - radius < 0 || position.x + radius > canvas_width || position.y - radius < 0 || position.y + radius > canvas_height)
		return true;
	else if( is_active == false )		// an den einai zwntano pia
		return true;
	else
		return false;
}

void GameObject::make_inactive()
{
	is_active = false;
}

float GameObject::getX()
{
	return position.x;
}

float GameObject::getY()
{
	return position.y;
}

float GameObject::getRadius()
{
	return radius;
}

GameObject::~GameObject()
{
}
