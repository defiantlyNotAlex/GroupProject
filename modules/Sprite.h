#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>

#include "damageCalculator.h"
#include <iostream>
#include <sstream>

class Sprite {
    private:
        int position[2]; // x, y position of the sprite
        int level;
        int attack;
        int defence;
        int type;
        int HPcapacity; // max HP of a character
        int HP;
    protected:
        sf::CircleShape* body;
        sf::RectangleShape* HP_bar;
        sf::Font font;
        sf::Text *HPText;
    public:
        // default constructor
        Sprite() {
            level = 1;
            attack = 10;
            defence = 2;
            HPcapacity = 100;
            HP = 100;
        }
        // constructor with customized level, attack, and HP capacity
        Sprite(int lvl, int attack, int defence, int type, int HPcapacity) {
            this->level = lvl;
            this->attack = attack;
            this->defence = defence;
            this->type = type;
            this->HPcapacity = HPcapacity;
            this->HP = HPcapacity;
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
            returnArray[6] = this->HPcapacity;
            returnArray[7] = this->HP;
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
            this->HPcapacity = atributes[6];
            this->HP = atributes[7];
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
        // draw HP bar
        void drawHPBar(int x, int y, sf::Color color) {
            HP_bar = new sf::RectangleShape(sf::Vector2f(50, 5)); // draw health bar
            HP_bar->setFillColor(color);
            HP_bar->setPosition(x,y);
        }
        // render the image in window - abstract class
        virtual void draw(sf::RenderWindow *win) = 0;
        // fight function
        void fight(Sprite *target, int attackType) {
            int damage = damageCalculator(this->attack+this->level, target->defence+target->level, target->type, attackType);
            // calculate the damage and apply it to the target
            target->HP -= damage;
            // if hp < 0 then hp = 0
            if (target->HP < 0) { target->HP = 0; }
            // change target's HP bar size
            target->changeHPBar();
        }
        // increments the level of the sprite
        void lvlUp() { 
            level++;
            HPcapacity++;
            attack++;
            defence++;
        }
        // set the position of the character
        void setPosition(int x, int y) {
            this->position[0] = x;
            this->position[1] = y;
        }
        // get the body, or the appearance, of the character
        sf::CircleShape *getBody() { return body; }
        // get the HP bar of the character
        sf::RectangleShape *getHPBar() { return HP_bar; }
        int getLvl() { return level; }
        // heals the sprite but stays below the max hp level
        void heal(int amount) {
            HP += amount;
            if (HP > HPcapacity) {
                HP = HPcapacity;
            }
        }
        // reset the level to 1 and the HP to full
        void reset() {
            level = 1;
            HP = HPcapacity;
        }
        // check if character is alive
        bool isAlive() {
            if (HP <= 0) {
                return false;
            }
            return true;
        }
        // HP bar change according to current HP
        void changeHPBar() {
            float proportion = (1.0 * HP) / (1.0 * HPcapacity);
            this->HP_bar->setScale(proportion, 1);
            changeHPText();
        }
        // display text to show the amount of HP lost
        void drawHPText() {
            if (!font.loadFromFile("fonts/courbd.ttf")) {
                std::cout << "Font not loading" << std::endl;
            }
            HPText = new sf::Text();
            HPText->setFont(font);
            HPText->setCharacterSize(12);
            std::stringstream formatText;
            formatText << HP << "/" << HPcapacity;
            HPText->setString(formatText.str());
            HPText->setFillColor(sf::Color::Red);
            HPText->setPosition(position[0]+50, position[1]-15);
        }
        // change HP text when HP changes
        void changeHPText() {
            std::stringstream formatText;
            formatText << HP << "/" << HPcapacity;
            HPText->setString(formatText.str());
        }
        // destructor
        ~Sprite() {
            delete body;
            delete HP_bar;
            delete HPText;
        }
};
#endif