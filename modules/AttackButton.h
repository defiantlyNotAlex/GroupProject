#ifndef ATTACKBUTTON_H
#define ATTACKBUTTON_H

#include <SFML/Graphics.hpp>
#include <string>
class AttackButton {
    private:
        sf::RectangleShape *body;
        sf::Text *text;
        int x, y;
        int type;
        int width = 50;
    public:
        // 1 = rock, 2 = paper, 3 = scissors
        AttackButton(int type, int x, int y) {
            this->x = x;
            this->y = y;
            body = new sf::RectangleShape(sf::Vector2f(width, width));
            body->setFillColor(sf::Color::White);
            body->setPosition(x, y);

            text = new sf::Text();
            text->setCharacterSize(20);
            switch(type) {
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
            text->setPosition(x, y);
        }
        // render attack button on window
        void draw(sf::RenderWindow *win) {
            win->draw(*body);
            win->draw(*text);
        }
        // get attack type of the character
        int getAttackType() {
            return type;
        }
        bool isClicked() {
            // if (body->getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) {
            //     if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            //         return true;
            //     }
            // }
            // return false;
        }
};
#endif