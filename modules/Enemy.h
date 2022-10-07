#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include "Sprite.h"

class Enemy: public Sprite {
    // private:

    public:
        Enemy(int x, int y): Sprite() {
            drawBody(x, y, sf::Color::Red);
        }
        ~Enemy() {}
};
#endif