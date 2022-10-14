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
        int* saveAtributes() { //x, y, level, attack, defence, type, maxHP, HP
            // returns the attributes of the sprite 
            int* returnArray = new int[8];
            returnArray[0] = this->position[0];
            returnArray[1] = this->position[1];
            returnArray[2] = this->level;
            returnArray[3] = this->attack;
            returnArray[4] = this->defence;
            returnArray[5] = this->position[type];
            returnArray[6] = this->HPcapacity;
            returnArray[7] = this->HP;
            return returnArray;
        }

        void loadAtributes(int* atributes) {
            this->position[0] = atributes[0];
            this->position[1] = atributes[1];
            this->level = atributes[2];
            this->attack = atributes[3];
            this->defence = atributes[4];
            this->position[type] = atributes[5];
            this->HPcapacity = atributes[6];
            this->HP = atributes[7];
        }
        // dont care about it:)) until the end.
        void drawBody(int x, int y, sf::Color color) { // draws the sprite based of its atributes
            position[0], position[1] = x, y; //poistion

            body = new sf::CircleShape();
            body->setRadius(10);
            body->setPosition(x,y);
            body->setFillColor(color);
            body->setOrigin(5,5);

            HP_bar = new sf::RectangleShape(sf::Vector2f(50, 5)); // draw health bar
            HP_bar->setFillColor(sf::Color::Green);
            HP_bar->setPosition(x-10,y-15);
        }
        // render the image in window
        void draw(sf::RenderWindow *win) {
            win->draw(*body);
            win->draw(*HP_bar);
        }

        void fight(Sprite *target, int attackType) { // fight function

            std::cout << "Prev: " << target->HP << std::endl; // print health to console

            // calculate the damage and apply it to the target
            target->HP -= damageCalculator(this->attack+this->level, target->defence+target->level, target->type, attackType);
            
            std::cout << "After: " << target->HP << std::endl;  // print health to console
            // change target's HP bar size
            target->changeHPBar(target->HP);
        }
        void lvlUp() { // increments the level of the sprite
            level++;
        }
        void heal(int amount) { // heals the sprite but stays below the max hp level
            HP += amount;
            if (HP > HPcapacity + level) {
                HP = HPcapacity + level;
            }
        }
        // check if character is alive
        bool isAlive() {
            if (HP <= 0) {
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