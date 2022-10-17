#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "Sprite.h"
#include <string>
#include <sstream>
#include <iostream>
class Player: public Sprite {
    private:
        sf::Font font;
        sf::Text* text;

    public:
        // constructor with variables: x, y, lvl, atk, def, HP capacity
        Player(int x, int y, int lvl, int attack, int defence, int HPcapacity): Sprite(lvl, attack, defence, 0, HPcapacity) {
            drawBody(x, y, sf::Color::Green);
            hp->drawHPBar(x-10, y-15, sf::Color::Green);
            printStats();
            drawTypeText(x, y+20);
            hp->drawHPText(x+50, y-15);
        }
        // print player statistics
        void printStats() {
            int* attributes = saveAtributes();
            if (!font.loadFromFile("fonts/courbd.ttf")) {
                std::cout << "Font not loading" << std::endl;
            }
            text = new sf::Text();
            text->setFont(font);
            text->setCharacterSize(12);
            std::stringstream formatText;
            formatText << "LVL: " << attributes[2] << "\nATK: " << attributes[3] << "\nDEF: " << attributes[4];
            text->setString(formatText.str());
            text->setFillColor(sf::Color::Red);
            text->setPosition(400,450);
        }
        // change player's statistic on screen
        void changePrintStats() {
            int* attributes = saveAtributes();
            std::stringstream formatText;
            formatText << "LVL: " << attributes[2] << "\nATK: " << attributes[3] << "\nDEF: " << attributes[4];
            text->setString(formatText.str());
        }
        // reset player's attributes
        void reset() {
            int newAttributes[8] = { 0, 250, 1, 50, 10, 0, 100, 100 };
            loadAtributes(newAttributes);
        }
        // render player on window
        void draw(sf::RenderWindow* win) {
            win->draw(*body);
            win->draw(*text);
            win->draw(*typeText);
            hp->draw(win);
        }
        // destructor
        ~Player() {
            delete text;
        }
};
#endif