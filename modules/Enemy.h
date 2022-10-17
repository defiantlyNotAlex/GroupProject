#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include "Sprite.h"
#include <iostream>
class Enemy: public Sprite {
    private:
        sf::Font font;
        sf::Text *text;
    public:
        int typing; // public variable for attacks

        // constructor with variables
        Enemy(int x, int y, int lvl, int type, int attack, int defence, int HPcapacity, sf::Color color): Sprite(lvl, attack, defence, type, HPcapacity) {
            typing = type;
            drawBody(x, y, color); 
            drawHPBar(x-10, y-15, sf::Color::Red);
            drawHPText();
            drawTypeText(x, y+20);
        }
        // constructor with different parameters
        Enemy(int x, int y, sf::Color color) {
            typing = 0;
            drawBody(x, y, color);
            drawHPBar(x-10, y-15, sf::Color::Red);
            drawHPText();
            drawTypeText(x, y+20);
        }
        // draw type text (rock/paper/scissor)
        void drawTypeText(int x, int y) {
            if (!font.loadFromFile("fonts/courbd.ttf")) {
                std::cout << "Font not loading" << std::endl;
            }
            text = new sf::Text();
            text->setFont(font);
            text->setCharacterSize(15);
            switch (typing) {
                case 1:
                    text->setString("Rock");
                    break;
                case 2:
                    text->setString("Paper");
                    break;
                case 3:
                    text->setString("Scissor");
                    break;
                default:
                    text->setString("No type");
                    break;
            }
            text->setFillColor(sf::Color::Red);
            text->setPosition(x, y);
        }
        // render enemy on window
        void draw(sf::RenderWindow* win) {
            win->draw(*body);
            win->draw(*HP_bar);
            win->draw(*text);
            win->draw(*HPText);
        }
        // destructor
        ~Enemy() {
            delete text;
        }
};
#endif