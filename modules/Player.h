#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "Sprite.h"
#include <string>
class Player: public Sprite {
    private:
        int playerLvl;
        int playerAttack;
        int playerDefence;

        sf::Font font;
        sf::Text* text;

    public:
        // constructor with variables
        Player(int x, int y, int lvl, int attack, int defence, int HPcapacity): Sprite(lvl, attack, defence, 0, HPcapacity) {
            drawBody(x, y, sf::Color::Green);
            playerLvl = lvl;
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
        void draw(sf::RenderWindow* win) {
            win->draw(*body);
            win->draw(*HP_bar);
        }
        // void printStats() {
        //     if (!font.loadFromFile("fonts/courbd.ttf")) {
        //         std::cout << "Font not loading" << std::endl;
        //     }
        //     text = new sf::Text();
        //     text->setFont(font);
        //     text->setCharacterSize(12);
        //     std::string formatText = "LVL" + playerLvl;
        //     text->setString(formatText);
        //     text->setFillColor(sf::Color::Red);
        //     text->setPosition(0,0);
        // }
        ~Player() {}
};
#endif