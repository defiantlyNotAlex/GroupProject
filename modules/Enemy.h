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
            
        }
        Enemy(int x, int y, sf::Color color) {
            typing = 0;
            drawBody(x, y, color);
            
        }
        void drawBody(int x, int y, sf::Color color) {
            setPosition(x, y);
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
                default:
                    text->setString("No type");
                    break;
            }
            text->setFillColor(sf::Color::Red);
            text->setPosition(x, y+20);
        }
        void draw(sf::RenderWindow* win) {
            win->draw(*body);
            win->draw(*HP_bar);
            win->draw(*text);
        }
        ~Enemy() {}
};
#endif