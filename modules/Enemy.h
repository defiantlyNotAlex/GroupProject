#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include "Sprite.h"

class Enemy: public Sprite {
    private:
        sf::CircleShape *body = getBody();
        sf::RectangleShape *HP_bar = getHPBar();
        sf::Font font;
        sf::Text *text;
    public:
        int typing; // public variable for attacks

        // constructor with variables
        Enemy(int x, int y, int lvl, int type, int attack, int defence, int HPcapacity): Sprite(lvl, attack, defence, type, HPcapacity) {
            drawBody(x, y, sf::Color::Red);
            typing = type;
        }
        Enemy() {
            drawBody(20, 20, sf::Color::Red);
            typing = 0;
        }
        void drawBody(int x, int y, sf::Color color) {
            body = new sf::CircleShape();
            body->setRadius(10);
            body->setPosition(x,y);
            body->setFillColor(color);
            body->setOrigin(5,5);

            HP_bar = new sf::RectangleShape(sf::Vector2f(50, 5)); // draw health bar
            HP_bar->setFillColor(sf::Color::Red);
            HP_bar->setPosition(x-10,y-15);

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
            }
            text->setFillColor(sf::Color::Red);
            text->setPosition(x, y+20);
        }
        ~Enemy() {}
};
#endif