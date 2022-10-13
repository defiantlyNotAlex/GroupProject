#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include "Sprite.h"

class Enemy: public Sprite {
    // private:

    public:
        Enemy(int x, int y, int lvl, int type, int attack, int defence, int HPcapacity): Sprite(lvl, attack, defence, type, HPcapacity) {
            drawBody(x, y, sf::Color::Red);
        }
        ~Enemy() {}
};
#endif
