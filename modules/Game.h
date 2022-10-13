#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "AttackButton.h"
using namespace sf;
class Game {
    private:
        RenderWindow *window;
        Player *player;
        Enemy* enemies[3];
        AttackButton *buttons[3];
    public:
        // constructor and initialize objects inside this
        Game(int size, std::string title) {
            window = new RenderWindow(VideoMode(size, size), title);
            player = new Player(size/2, size*3/4, 1, 40, 5, 100);
            for (int i=0; i<3; i++) {
                enemies[i] = new Enemy(size*(i+1)/4, size/4, 1, 2, 10, 20, 100);
            }

            //Declare a Font object

            //Load and check the availability of the font file

            // attack buttons
            buttons[0] = new AttackButton(1, 5, size-55);
            buttons[1] = new AttackButton(2, 60, size-55);
            buttons[2] = new AttackButton(3, 115, size-55);
        }
        void run() {
            while (window->isOpen()) {
                Event e;
                // all events happen inside this while loop
                while (window->pollEvent(e)) {
                    if (e.type == Event::Closed) {
                        window->close();
                    }
                    // attack aka game starts
                    while (player->isAlive() && checkAllEnemiesAlive()) {

                    }
                }

                window->clear();

                // render all assets below
                player->draw(window);
                for (int i=0; i<3; i++) {
                    enemies[i]->draw(window);
                    buttons[i]->draw(window);
                }

                // display window
                window->display();
            }
        }
        bool checkAllEnemiesAlive() {
            for (int i=0; i<3; i++) {
                if (!enemies[i]->isAlive()) {
                    return false;
                }
            }
            return true;
        }
        ~Game() {}
};
#endif
