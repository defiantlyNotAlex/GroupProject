#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include "Character.h"
#include <iostream>
class Enemy: public Character {
    private:
    public:
        int typing; // public variable for attacks

        // constructor with variables: x, y, lvl, type, atk, def, HP capacity, color
        Enemy(int x, int y, int lvl, int type, int attack, int defence, int HPcapacity, sf::Color color): Character(lvl, attack, defence, type, HPcapacity) {
            typing = type;
            drawBody(x, y, color); 
            hp->drawHPBar(x-10, y-15, sf::Color::Red);
            hp->drawHPText(x+50, y-15);
            drawTypeText(x, y+20);
        }
        // draw type typeText (rock/paper/scissor)
        void drawTypeText(int x, int y) {
            typeText = new sf::Text();
            typeText->setFont(font);
            typeText->setCharacterSize(15);
            switch (typing) {
                case 1:
                    typeText->setString("Rock");
                    break;
                case 2:
                    typeText->setString("Paper");
                    break;
                case 3:
                    typeText->setString("Scissor");
                    break;
                default:
                    typeText->setString("No type");
                    break;
            }
            typeText->setFillColor(sf::Color::Red);
            typeText->setPosition(x, y);
        }
        // render enemy on window
        void draw(sf::RenderWindow* win) {
            win->draw(*body);
            win->draw(*typeText);
            hp->draw(win);
        }
        // destructor
        ~Enemy() {
        }
};
#endif