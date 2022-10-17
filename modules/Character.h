#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>

#include "damageCalculator.h"
#include "HP.h"
#include <iostream>
#include <sstream>

class Character {
    private:
        int position[2]; // x, y position of the sprite
        int level;
        int attack;
        int defence;
        int type;
    protected:
        sf::CircleShape* body;
        sf::Text *typeText;
    public:
        sf::Font font;
        HP *hp;

        // default constructor
        Character() {
            level = 1;
            attack = 10;
            defence = 2;
            hp = new HP(100, 100);
            if (!font.loadFromFile("fonts/courbd.ttf")) {
                std::cout << "Font not loading" << std::endl;
            }
        }
        // constructor with customized level, attack, and HP capacity
        Character(int lvl, int attack, int defence, int type, int HPcapacity) {
            this->level = lvl;
            this->attack = attack;
            this->defence = defence;
            this->type = type;
            hp = new HP(HPcapacity, HPcapacity);
            if (!font.loadFromFile("fonts/courbd.ttf")) {
                std::cout << "Font not loading" << std::endl;
            }
        }
        // save player's attributes to array
        //x, y, level, attack, defence, type, maxHP, HP
        int* saveAtributes() { 
            // returns the attributes of the sprite 
            int* returnArray = new int[8];
            returnArray[0] = this->position[0];
            returnArray[1] = this->position[1];
            returnArray[2] = this->level;
            returnArray[3] = this->attack;
            returnArray[4] = this->defence;
            returnArray[5] = this->type;
            returnArray[6] = this->hp->HPcapacity;
            returnArray[7] = this->hp->currentHP;
            return returnArray;
        }
        // load player's attributes from array
        //x, y, level, attack, defence, type, maxHP, HP
        void loadAtributes(int* atributes) {
            this->position[0] = atributes[0];
            this->position[1] = atributes[1];
            this->level = atributes[2];
            this->attack = atributes[3];
            this->defence = atributes[4];
            this->type = atributes[5];
            this->hp->HPcapacity = atributes[6];
            this->hp->currentHP = atributes[7];
        }
        // draw body
        void drawBody(int x, int y, sf::Color color) {
            setPosition(x, y);
            body = new sf::CircleShape();
            body->setRadius(10);
            body->setPosition(x,y);
            body->setFillColor(color);
            body->setOrigin(5,5);
        }
        // type text - polymorphism
        void drawTypeText(int x, int y) {
            typeText = new sf::Text();
            typeText->setFont(font);
            typeText->setCharacterSize(15);
            typeText->setString("You");
            typeText->setFillColor(sf::Color::Green);
            typeText->setPosition(x, y);
        }
        // render the image in window - abstract class
        virtual void draw(sf::RenderWindow *win) = 0;
        // fight function
        void fight(Character *target, int attackType) {
            int damage = damageCalculator(this->attack+this->level, target->defence+target->level, target->type, attackType);
            // calculate the damage and apply it to the target
            target->hp->currentHP -= damage;
            // if hp < 0 then hp = 0
            if (target->hp->currentHP < 0) { target->hp->currentHP = 0; }
            // change target's HP bar size
            target->hp->changeHPBar();
        }
        // increments the level of the sprite
        void lvlUp() { 
            level++;
            hp->HPcapacity++;
            attack++;
            defence++;
        }
        // set the position of the character
        void setPosition(int x, int y) {
            this->position[0] = x;
            this->position[1] = y;
        }
        int getLvl() { return level; }
        // heals the sprite but stays below the max hp level
        void heal(int amount) {
            hp->currentHP += amount;
            if (hp->currentHP > hp->HPcapacity) {
                hp->currentHP = hp->HPcapacity;
            }
        }
        // check if character is alive
        bool isAlive() {
            if (hp->currentHP <= 0) {
                return false;
            }
            return true;
        }
        // destructor
        ~Character() {
            delete body;
            delete typeText;
            delete hp;
        }
};
#endif