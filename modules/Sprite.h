#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>

#include "damageCalculator.h"
#include <iostream>

class Sprite {
    private:
        sf::CircleShape *body;
        sf::RectangleShape *HP_bar;
        int position[2]; // x, y position of the sprite
        int level;
        int exp;
        int attack;
        int defence;
        int type;
        int HPcapacity; // max HP of a character
        int HP;
    public:
        // default constructor
        Sprite() {
            level = 1;
            attack = 10;
            defence = 2;
            HPcapacity = 100;
            HP = 100;
            exp = 0;
        }
        // constructor with customized level, attack, and HP capacity
        Sprite(int lvl, int attack, int defence, int type, int HPcapacity) {
            level = lvl;
            this->attack = attack;
            this->defence = defence;
            this->type = type;
            this->HPcapacity = HPcapacity;

            exp = 0;
            HP = HPcapacity;
        }
        // dont care about it:)) until the end.
        void drawBody(int x, int y, sf::Color color) {
            position[0], position[1] = x, y;
            body = new sf::CircleShape();
            body->setRadius(10);
            body->setPosition(x,y);
            body->setFillColor(color);
            body->setOrigin(5,5);

            HP_bar = new sf::RectangleShape(sf::Vector2f(50, 5));
            HP_bar->setFillColor(sf::Color::Green);
            HP_bar->setPosition(x-10,y-15);
        }
        // render the image in window
        void draw(sf::RenderWindow *win) {
            win->draw(*body);
            win->draw(*HP_bar);
        }
        // fight function - need to add more attack effect
        void fight(Sprite *enemy) {
            int *enemyPosition = enemy->getPosition();
            std::cout << "Prev: " << enemy->HP << std::endl;
            if (enemy->HP - damageCalculator(this->attack, enemy->defence, enemy->type, this->type)  < 0) {
                enemy->HP = 0;
            } else {
                enemy->HP -= damageCalculator(this->attack, enemy->defence, enemy->type, this->type);
            }
            std::cout << "After: " << enemy->HP << std::endl;
            // change enemy's HP bar size
            enemy->changeHPBar(enemy->HP);
        }
        // check if character is alive
        bool isAlive() {
            if (HP == 0) {
                return false;
            }
            return true;
        }
        // get the x, y position of the character
        int* getPosition() {
            return position;
        }
        // HP bar change according to current HP
        void changeHPBar(int currentHP) {
            float proportion = 1.0 * currentHP / HPcapacity;
            std::cout << proportion << std::endl;
            this->HP_bar->setScale(proportion, 1);
        } 
        ~Sprite() {}
};
#endif
