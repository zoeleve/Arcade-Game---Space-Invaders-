#pragma once

#include "Point2D.h"
#include "graphics.h"
#include "Configuration.h"

// Yperklasi gia ola ta antikeimena tou paixnidiou
class GameObject
{
protected:

	float radius;				// Aktina antikeimenou gia tis sigkrouseis
	Point2D position;			// Thesi antikeimenou x,y
	graphics::Brush brush;		// Brush tin apeikonisi tou antikeimenou
	bool is_active;				// An einai energo h oxi sto paixnidi (ta mi energa ginontai delete)

public:

	GameObject(float x, float y, float r);

	// Koitazei na dei an einai ektos tou camva h anenergo
	bool is_out();

	// Kanei to GameObject anergo
	void make_inactive();

	// Pure virtual gia na tis exoun kai oi ypoklaseis
	virtual void draw() = 0;
	virtual void update() = 0;

	// Getter
	float getX();
	float getY();
	float getRadius();

	virtual ~GameObject();
};

