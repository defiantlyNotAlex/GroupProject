#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <string>
#include <stack>
#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "AttackButton.h"

using namespace sf;

class Game {
    private:
        RenderWindow *window;
        Player *player;
        std::stack <Enemy*> enemies;  
        // enemies declared as a stack so that dead enemies can be easily removed and new enemies added easily
        AttackButton *buttons[3];
    public:
        // constructor and initialize objects inside this
        Game(int size, std::string title) {
            window = new RenderWindow(VideoMode(size, size), title);
            player = new Player(size/2, size*3/4, 1, 40, 5, 100);
            for (int i=0; i<3; i++) {
                enemies.push(new Enemy(size*(i+1)/4, size/4, 1, 2, 10, 20, 100)); // x, y, level, type, attackstat, defence stat, max hp
            }

            buttons[0] = new AttackButton("Rock", 5, size-55, 1); // add three buttons one of each type
            buttons[1] = new AttackButton("Paper", 65, size-55, 2);
            buttons[2] = new AttackButton("Scissor", 125, size-55, 3);
        }
        void run() {
            while (window->isOpen()) {
                Event e;
                // all events happen inside this while loop
                while (window->pollEvent(e)) {
                    if (e.type == Event::Closed) {
                        window->close();
                    }
                    // temporary attack
                    /*if (Keyboard::isKeyPressed(Keyboard::Space)) {
                        std::cout << "Key pressed" << std::endl;
                        player->fight(enemies.top(), enemies.top()->typing);
                        enemies.top()->fight(player);
                    }*/
                    if (!enemies.top()->isAlive() && enemies.size() > 1) { // if the enemy dies
                        enemies.pop(); // delete the enemy
                        player->lvlUp(); // level up the player
                        player->heal(50); // heal the player
                    }
                    if (Mouse::isButtonPressed(Mouse::Left)) // if the player clicks
                    {
                        Vector2i mousePos = Mouse::getPosition()-window->getPosition()-Vector2i(10, 45); 
                        // get the mouse position relative to the window (getPosition gets the mouse position on the screen)
                        std::cout << "m1/" << mousePos.x << "/" << mousePos.y << std::endl; // print mouse position

                        for (int i = 0; i < 3; i++) { // for each attack button
                            if (mousePos.x < buttons[i]->position.x + buttons[i]->size.x &&
                                mousePos.x > buttons[i]->position.x &&
                                mousePos.y < buttons[i]->position.y + buttons[i]->size.y &&
                                mousePos.y > buttons[i]->position.y) // if the cursor is inside the bounds of the button
                            {
                                player->fight(enemies.top(), buttons[i]->attackType); // the player attacks the enemy using the type from the button

                                enemies.top()->fight(player, enemies.top()->typing); // the enemy does its turn attacking the player

                            }
                        }
                    }

                    
                }

                window->clear();

                // render all assets below
                player->draw(window);
                for (int i=0; i<3; i++) {
                    buttons[i]->draw(window);
                }
                enemies.top()->draw(window); // only draw the active enemy

                // display window
                window->display();
            }
        }
        ~Game() {}
};
#endif