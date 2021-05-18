#pragma once

#include "GameObject.h"

class Alien : public GameObject
{
protected:
	int life;
	float speed;
	float Fx;
	float Fy;

public:

	Alien(float x, float y, float r);
	void hit();
	bool isLive();
	void draw();
	void update();
};


class OctapusAlien : public Alien
{
public:
	OctapusAlien(float x, float y);
};


class SciFiAlien : public Alien
{
public:
	SciFiAlien(float x, float y);
};