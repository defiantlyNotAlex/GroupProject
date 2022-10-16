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
        // constructor with variables
        Player(int x, int y, int lvl, int attack, int defence, int HPcapacity): Sprite(lvl, attack, defence, 0, HPcapacity) {
            drawBody(x, y, sf::Color::Green);
            printStats();
            setHPText();
        }
        void drawBody(int x, int y, sf::Color color) { // draws the sprite based of its atributes
            setPosition(x, y);

            body = new sf::CircleShape();
            body->setRadius(10);
            body->setPosition(x,y);
            body->setFillColor(color);
            body->setOrigin(5,5);

            HP_bar = new sf::RectangleShape(sf::Vector2f(50, 5)); // draw health bar
            HP_bar->setFillColor(sf::Color::Green);
            HP_bar->setPosition(x-10,y-15);
        }
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
        void changePrintStats() {
            int* attributes = saveAtributes();
            std::stringstream formatText;
            formatText << "LVL: " << attributes[2] << "\nATK: " << attributes[3] << "\nDEF: " << attributes[4];
            text->setString(formatText.str());
        }
        void draw(sf::RenderWindow* win) {
            win->draw(*body);
            win->draw(*HP_bar);
            win->draw(*text);
            win->draw(*HPText);
        }
        ~Player() {}
};
#endif