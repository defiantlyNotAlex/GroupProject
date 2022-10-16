#ifndef ESC_H
#define ESC_H
#include <SFML/Graphics.hpp>
#include "Enemy.h"

class Rock : public Enemy {
    // private:

public:
    int typing; // public variable for attacks

    // constructor
    Rock(int x, int y) : Enemy(250, 20, 10, 1, 50, 1, 50) {
        drawBody(x, y, sf::Color::Green);
        typing = 1;
    }
    Rock() : Enemy(250, 20, 10, 1, 50, 1, 50) {
        drawBody(250, 20, sf::Color::Green);
        typing = 1;
    }
};
class Paper : public Enemy {
    // private:

public:
    int typing; // public variable for attacks

    // constructor
    Paper(int  x, int y) : Enemy(250, 20, 10, 2, 50, 1, 50) {
        drawBody(x, y, sf::Color::Red);
        typing = 2;
    }
    Paper() : Enemy(250, 20, 10, 2, 50, 1, 50) {
        drawBody(250, 20, sf::Color::Red);
        typing = 2;
    }
};
class Scissor : public Enemy {
    // private:

public:
    int typing; // public variable for attacks

    // constructor
    Scissor(int x, int  y) : Enemy(x, y, 10, 3, 50, 1, 50) {
        drawBody(250, 20, sf::Color::Blue);
        typing = 3;
    }
    Scissor() : Enemy(250, 20, 10, 3, 50, 1, 50) {
        drawBody(250, 20, sf::Color::Blue);
        typing = 3;
    }
};
#endif