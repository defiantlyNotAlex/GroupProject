#ifndef HP_H
#define HP_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
class HP {
    public:
        int currentHP;
        int HPcapacity;
        sf::Font font;
        sf::RectangleShape* HP_bar;
        sf::Text *HPText;
        // constructor: current HP, HP capacity
        HP(int currentHP, int HPcapacity) {
            this->currentHP = currentHP;
            this->HPcapacity = HPcapacity;
        }
        // draw HP bar
        void drawHPBar(int x, int y, sf::Color color) {
            HP_bar = new sf::RectangleShape(sf::Vector2f(50, 5)); // draw health bar
            HP_bar->setFillColor(color);
            HP_bar->setPosition(x,y);
        }
        // display text to show the amount of HP
        void drawHPText(int x, int y) {
            if (!font.loadFromFile("fonts/courbd.ttf")) {
                std::cout << "Font not loading" << std::endl;
            }
            HPText = new sf::Text();
            HPText->setFont(font);
            HPText->setCharacterSize(12);
            std::stringstream formatText;
            formatText << currentHP << "/" << HPcapacity;
            HPText->setString(formatText.str());
            HPText->setFillColor(sf::Color::Red);
            HPText->setPosition(x, y);
        }
        // HP bar change according to current HP
        void changeHPBar() {
            float proportion = (1.0 * currentHP) / (1.0 * HPcapacity);
            this->HP_bar->setScale(proportion, 1);
            changeHPText();
        }
        // change HP text when HP changes
        void changeHPText() {
            std::stringstream formatText;
            formatText << currentHP << "/" << HPcapacity;
            HPText->setString(formatText.str());
        }
        // render in window
        void draw(sf::RenderWindow* win) {
            win->draw(*HP_bar);
            win->draw(*HPText);
        }
        // destructor
        ~HP() {
            delete HP_bar;
            delete HPText;
        }
};
#endif