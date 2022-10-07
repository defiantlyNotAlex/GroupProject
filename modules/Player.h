#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "Sprite.h"

class Player: public Sprite {
    // private:

    public:
        Player(int x, int y): Sprite() {
            drawBody(x, y, sf::Color::Green);
        }
        ~Player() {}
};
#endif