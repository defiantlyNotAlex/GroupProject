#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>

class Sprite {
    private:
        sf::CircleShape *body;
        sf::RectangleShape *HP_bar;
        int level;
        int exp;
        int attack;
        int HPcapcity;
        int HP;
    public:
        Sprite() {
            level = 1;
            attack = 10;
            HPcapcity = 100;
            HP = 100;
            exp = 0;
        }
        void drawBody(int x, int y, sf::Color color) {
            body = new sf::CircleShape();
            body->setRadius(10);
            body->setPosition(x,y);
            body->setFillColor(color);
            body->setOrigin(5,5);

            HP_bar = new sf::RectangleShape(sf::Vector2f(50, 5));
            HP_bar->setOutlineColor(sf::Color::White);
            HP_bar->setPosition(x-10,y-15);
        }
        void draw(sf::RenderWindow *win) {
            win->draw(*body);
            win->draw(*HP_bar);
        }
        // fight function - need to add more attack effect
        void fight(Sprite *enemy) {
            enemy->HPcapcity -= this->attack;
        }
        ~Sprite() {}
};
#endif