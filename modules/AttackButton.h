#ifndef ATTACKBUTTON_H
#define ATTACKBUTTON_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
// player's attack button with three types:
// 1: rock, 2: paper, 3: scissor
class AttackButton {
    private:
        sf::RectangleShape *body;
        sf::Font font;
        sf::Text *text;
    public:
        sf::Vector2i position;
        sf::Vector2i size;
        int attackType;
        // constructor
        AttackButton(std::string type, int x, int y, int attack_Type) {
            // stuff for rendering
            drawBody(x, y);
            drawText(x, y+20, type);

            // variables needed for functionality
            position = sf::Vector2i(x, y); // position stores the x, y value of the top right of the button
            size = sf::Vector2i(50, 50);   // size stores the width and height of the button 
            attackType = attack_Type;      // attackType stores what kind of attack the button will dp]o
        }
        // draw button body
        void drawBody(int x, int y) {
            body = new sf::RectangleShape(sf::Vector2f(50, 50));
            body->setFillColor(sf::Color::White);
            body->setPosition(x, y);
        }
        // draw button text
        void drawText(int x, int y, std::string type) {
            if (!font.loadFromFile("fonts/courbd.ttf")) {
                std::cout << "Font not loading" << std::endl;
            }
            text = new sf::Text();
            text->setFont(font);
            text->setCharacterSize(12);
            text->setString(type);
            text->setFillColor(sf::Color::Red);
            text->setPosition(x, y);
        }
        // render button in window
        void draw(sf::RenderWindow *win) { // draw the button
            win->draw(*body);
            win->draw(*text);
        }
        // destructor
        ~AttackButton() {
            delete body;
            delete text;
        }
};
#endif