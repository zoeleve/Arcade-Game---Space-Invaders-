#include "GameStatus.h"
#include "GameStatus.h"

#include <string>

using namespace std;

GameStatus::GameStatus():GameObject(0, 0, 0)	// agnooume tin thesi kai tin aktina
{
	score = 0;
	lifes = 4;

	// Wste na parei to eikonidio to kathena
	heart.texture = string(assets_path) + "heart.png";
	heart.fill_opacity = 1.0f;
	heart.outline_opacity = 0.0f;

	coin.texture = string(assets_path) + "score.png";
	coin.fill_opacity = 1.0f;
	coin.outline_opacity = 0.0f;

	// Xrwma to grammatwn
	brush.fill_color[0] = 1.0f;
	brush.fill_color[1] = 0.0f;
	brush.fill_color[2] = 1.0f;
}

void GameStatus::draw()
{
	string score_string = "Score ("+to_string(score)+")";
	graphics::drawRect( 20, 20, 25, 25, coin);
	graphics::drawText( 70, 20, 20, score_string, brush);

	// Wste na zwgrafisei oles tis kardies pou exoun meinei
	if (lifes <= 4)
	{
		graphics::drawRect(canvas_width - 200, canvas_height + 20, 25, 25, heart);

		if (lifes <= 3)
		{
			graphics::drawRect(canvas_width - 175, canvas_height + 20, 25, 25, heart);

			if (lifes <= 2)
			{
				graphics::drawRect(canvas_width - 150, canvas_height + 20, 25, 25, heart);

				if (lifes == 1)
				{
					graphics::drawRect(canvas_width - 125, canvas_height + 20, 25, 25, heart);
				}
			}
		}
	}
}

void GameStatus::update()
{
}

void GameStatus::score_up()
{
	score++;
}

void GameStatus::score_double_up()
{
	score = score + 2;
}

void GameStatus::score_pentuple_up()
{
	score = score + 5;
}

void GameStatus::lifes_down()
{
	if (lifes > 0)
		lifes--;
}

long GameStatus::get_score()
{
	return score;
}

int GameStatus::get_lifes()
{
	return lifes;
}

bool GameStatus::game_over()
{
	if (lifes == 0)
		return true;
	else
		return false;
}
