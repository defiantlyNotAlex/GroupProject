#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include "Sprite.h"

class Enemy: public Sprite {
    // private:

    public:
        Enemy(int x, int y, int lvl, int attack, int HPcapacity): Sprite(lvl, attack, HPcapacity) {
            drawBody(x, y, sf::Color::Red);
        }
        ~Enemy() {}
};
#endif