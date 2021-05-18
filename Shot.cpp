#include "Shot.h"

Shot::Shot(SpaceInvadersGame& g, float s, float x, float y, float r):GameObject(x,y,r), game(g)
{
    speed = s;

    // einonidio stin sfaira
    brush.texture = string(assets_path) + "bullet.png";
}

void Shot::draw()
{
    // To apeikonizei an einai enargopoihmeno
    if (is_active == true)
        graphics::drawRect(position.x, position.y, radius, radius, brush);
}

void Shot::update()
{
    // H sfaira paei pros ta panw stin othoni ara meiwnetai to y
    position.y = position.y - speed*graphics::getDeltaTime()/10.0f;
}

void Shot::collision_with_alien(GameObject* object)
{
    // Wste na dei an einai typou Alien to GameObject
    Alien* alien = dynamic_cast<Alien*>(object);

    // an einai Alien, tote i sfaira apergopoieitai kai to alien pathainei damage kai anevainei to skor
    if (alien != nullptr && alien->is_out() == false )
    {
        float distance = sqrt(pow(position.x - object->getX(), 2) + pow(position.y - object->getY(), 2));

        if (distance < radius + object->getRadius())
        {
            is_active = false;
            alien->hit();

            game.score_up();

            // Analoga to eidos anevainei kai to skor 2 pontoi gia ta Octapus
            // 5 pontoi gia ta SciFi
            OctapusAlien* octapusalien = dynamic_cast<OctapusAlien*>(object);
            if (octapusalien != nullptr)
            {
                game.score_double_up();
            }

            SciFiAlien* scifialien = dynamic_cast<SciFiAlien*>(object);
            if (scifialien != nullptr)
            {
                game.score_pentuple_up();
            }

            // Wste na paixei ixo
            graphics::playSound(string(assets_path) + "hit1.wav", 1.0f);
        }
    }
    
}
