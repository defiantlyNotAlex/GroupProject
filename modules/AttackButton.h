#ifndef ATTACKBUTTON_H
#define ATTACKBUTTON_H

#include <SFML/Graphics.hpp>
#include <string>
class AttackButton {
    private:
        sf::RectangleShape *body;
        sf::Text *text;
        int type;
    public:
        // 1 = rock, 2 = paper, 3 = scissors
        AttackButton(int type, int x, int y) {
            body = new sf::RectangleShape(sf::Vector2f(50, 50));
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
        void draw(sf::RenderWindow *win) {
            win->draw(*body);
            win->draw(*text);
        }
};
#endif