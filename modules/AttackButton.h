#ifndef ATTACKBUTTON_H
#define ATTACKBUTTON_H

#include <SFML/Graphics.hpp>
#include <string>
class AttackButton {
    private:
        sf::RectangleShape *body;
        sf::Text *text;
    public:
        AttackButton(std::string type, int x, int y) {
            body = new sf::RectangleShape(sf::Vector2f(50, 50));
            body->setFillColor(sf::Color::White);
            body->setPosition(x, y);

            text = new sf::Text();
            text->setCharacterSize(20);
            text->setString(type);
            text->setFillColor(sf::Color::Red);
            text->setPosition(x, y);
        }
        void draw(sf::RenderWindow *win) {
            // win->draw(*body);
            win->draw(*text);
        }
};
#endif