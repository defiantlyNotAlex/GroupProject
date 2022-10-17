#include <SFML/Graphics.hpp>
#include "modules/Game.h"
#include <iostream>
#include <string>
void test(bool res, std::string testName) {
    if(!res) {
        std::cout << "Test failed: " << testName << std:: endl;
    }
}
void tests() {
    // test Character class (using Enemy/Player class since Character is abstract)
    {
        // test fight()
        {
            Enemy e(20, 20, 5, 1, 50, 10, 100, sf::Color::Red);
            Player p(20, 20, 5, 60, 20, 100);
            e.fight(&p, 1);
            bool res = p.hp->currentHP == 98;
            test(res, "Character::fight()");
        }
        // test heal()
        {
            Enemy e(20, 20, 5, 1, 50, 10, 100, sf::Color::Red);
            Player p(20, 20, 5, 60, 20, 100);
            e.fight(&p, 1);
            p.heal(1);
            bool res = p.hp->currentHP == 99;
            test(res, "Character::heal()");
        }
        // test isAlive()
        {
            Player p(20, 20, 5, 60, 20, 100);
            bool res = p.isAlive() == true;
            test(res, "Character::isAlive()");
        }
    }
}