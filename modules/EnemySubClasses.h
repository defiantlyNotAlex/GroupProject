#ifndef ESC_H
#define ESC_H
#include <SFML/Graphics.hpp>
#include "Enemy.h"
int const x = 250;
int const y = 60;
// Rock Enemy
class Rock : public Enemy {
    // private:

public:
    int typing; // public variable for attacks

    // constructor
    Rock() : Enemy(x, y, 10, 1, 50, 1, 50, sf::Color::Red) {
        typing = 1;
    }
};
// Paper Enemy
class Paper : public Enemy {
    // private:

public:
    int typing; // public variable for attacks

    // constructor
    Paper() : Enemy(x, y, 10, 2, 50, 1, 50, sf::Color::Blue) {
        typing = 2;
    }
};
// Scissor Enemy
class Scissor : public Enemy {
    // private:

public:
    int typing; // public variable for attacks

    // constructor
    Scissor() : Enemy(x, y, 10, 3, 50, 1, 50, sf::Color::Yellow) {
        typing = 3;
    }
};
#endif