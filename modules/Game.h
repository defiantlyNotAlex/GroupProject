#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Player.h"
#include "Enemy.h"
using namespace sf;
class Game {
    private:
        RenderWindow *window;
        Player *player;
        Enemy* enemies[3];
    public:
        Game(int size, std::string title) {
            window = new RenderWindow(VideoMode(size, size), title);
            player = new Player(size/2, size*3/4);
            for (int i=0; i<3; i++) {
                enemies[i] = new Enemy(size*(i+1)/4, size/4);
            }
        }
        void run() {
            while (window->isOpen()) {
                Event e;
                while (window->pollEvent(e)) {
                    if (e.type == Event::Closed) {
                        window->close();
                    }
                }
                window->clear();
                player->draw(window);
                for (int i=0; i<3; i++) {
                    enemies[i]->draw(window);
                }
                window->display();
            }
        }
        ~Game() {}
};
#endif