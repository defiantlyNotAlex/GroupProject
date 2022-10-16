#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>

#include "damageCalculator.h"
#include <iostream>

class Sprite {
    private:
        int position[2]; // x, y position of the sprite
        int level;
        int exp;
        int attack;
        int defence;
        int type;
        int HPcapacity; // max HP of a character
        int HP;
    protected:
        sf::CircleShape* body;
        sf::RectangleShape* HP_bar;
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
        //x, y, level, attack, defence, type, maxHP, HP
        int* saveAtributes() { 
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
        //x, y, level, attack, defence, type, maxHP, HP
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

        virtual void drawBody(int x, int y, sf::Color color) = 0;
        // render the image in window
        virtual void draw(sf::RenderWindow *win) = 0;

        void fight(Sprite *target, int attackType) { // fight function
            // calculate the damage and apply it to the target
            target->HP -= damageCalculator(this->attack+this->level, target->defence+target->level, target->type, attackType);
            // if hp < 0 then hp = 0
            if (target->HP < 0) {target->HP = 0;}
            // change target's HP bar size
            target->changeHPBar(target->HP);
        }
        void lvlUp() { // increments the level of the sprite
            level++;
        }
        void setPosition(int x, int y) {
            this->position[0] = x;
            this->position[1] = y;
        }
        sf::CircleShape *getBody() { return body; }
        sf::RectangleShape *getHPBar() { return HP_bar; }
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
        // HP bar change according to current HP
        void changeHPBar(int currentHP) {
            float proportion = (1.0 * currentHP) / (1.0 * HPcapacity);
            this->HP_bar->setScale(proportion, 1);
        } 
        ~Sprite() {
            delete body;
            delete HP_bar;
        }
};
#endif