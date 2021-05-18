#pragma once

#include "GameObject.h"

// Klasi pou exei to skor kai to ypoloipo ths zwhs
class GameStatus : public GameObject
{
private:
	int lifes;			// Ipoloipo zwis
	long score;			// Score

	graphics::Brush heart;			// Eikonidio kardias
	graphics::Brush coin;			// Eikonidio nomismatos

public:

	GameStatus();

	void draw();
	void update();

	// Wste na auxanetai to skor ana 1,2 h 5
	void score_up();
	void score_double_up();
	void score_pentuple_up();

	// Wste na meiwnontai oi zwes
	void lifes_down();

	// Getter
	long get_score();
	int get_lifes();
	bool game_over();
};

