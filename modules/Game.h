#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <string>
#include <cstring>
#include <stack>
#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "AttackButton.h"
#include <fstream>
#include <cstdlib>
#include "EnemySubClasses.h"

using namespace std;
using std::ofstream;
using namespace sf;

class Game {
    private:
        ofstream outdata;
        RenderWindow *window;
        Player *player;
        std::stack <Enemy*> enemies;  
        // enemies declared as a stack so that dead enemies can be easily removed and new enemies added easily
        AttackButton *buttons[3];
        // sf::Font font;
    public:
        // constructor and initialize objects inside this
        Game(int size, std::string title) {
            window = new RenderWindow(VideoMode(size, size), title);
            player = new Player(size/2, size*3/4, 1, 40, 5, 100);
            

            buttons[0] = new AttackButton("Rock", 5, size-55, 1); // add three buttons one of each type
            buttons[1] = new AttackButton("Paper", 65, size-55, 2);
            buttons[2] = new AttackButton("Scissor", 125, size-55, 3);

            this->load();
            if (enemies.size() == 0) {
                this->reset();
            }
        }
        void save() {
            outdata.open("test.txt");
            if (!outdata) { // file couldn't be opened
                cout << "Error: file could not be opened" << endl;
                exit(1);
            }
            else
            {
                int* atributes = player->saveAtributes();
                for (int i = 0; i < 8; i++) {
                    outdata << atributes[i] << ",";
                }
                outdata << endl;
                //std::cout << "file opened" << endl;
                while (enemies.size() > 0) {
                    int* atributes = enemies.top()->saveAtributes();
                    for (int i = 0; i < 8; i++) {
                        outdata << atributes[i] << ",";
                    }
                    outdata << endl;
                    enemies.pop();
                }
            }

            outdata.close();
        }
        void load() {
            // load player attributes
            ifstream MyReadFile("test.txt");
            string line;
            int* atributes = new int[8];
            getline(MyReadFile, line);
            //cout << line << endl;
            int j = 0;
            for (int i = 0; i < 8; i++) {
                string segment = "";
                while (line[j] != ',') {
                    segment += line[j];
                    j++;
                }
                
                j++;
                atributes[i] = stoi(segment);
            }
            
            player->loadAtributes(atributes);
            player->changePrintStats();
            // load enemy attributes
            while (getline(MyReadFile, line)) {
                int j = 0;
                for (int i = 0; i < 8; i++) {
                    string segment = "";
                    while (line[j] != ',') {
                        segment += line[j];
                        j++;
                    }
                    
                    j++;
                    atributes[i] = stoi(segment);
                }
                enemies.push(new Enemy());
                enemies.top()->loadAtributes(atributes);
            }
            if (enemies.size() == 0) {
                this->reset();
            }
        }
        void reset() {
            while (!enemies.empty())
                enemies.pop();
            for (int i = 0; i < 3; i++) {
                enemies.push(new Rock()); // x, y, level, type, attackstat, defence stat, max hp
                enemies.push(new Paper());
                enemies.push(new Scissor());
            }
        }
        void run() {
            while (window->isOpen()) {
                Event e;
                // all events happen inside this while loop
                while (window->pollEvent(e)) {
                    // save the enemy states
                    if (e.type == Event::Closed) {
                        this->save();
                        window->close();
                    }
                    
                    if (!enemies.top()->isAlive()) { // if the enemy dies
                        enemies.pop(); // delete the enemy
                        player->lvlUp(); // level up the player
                        player->heal(50); // heal the player
                        if (enemies.size() == 0) {
                            this->save();
                            cout << "YOU WIN" << endl;
                            this->reset();
                        }
                        player->changePrintStats();
                    }
                    if (!player->isAlive()) {
                        cout << "YOU LOSE" << endl;
                        this->load();
                    }
                    if (Mouse::isButtonPressed(Mouse::Left)) // if the player clicks
                    {
                        Vector2i mousePos = Mouse::getPosition()-window->getPosition()-Vector2i(10, 45); 
                        // get the mouse position relative to the window (getPosition gets the mouse position on the screen)
                        //std::cout << "m1/" << mousePos.x << "/" << mousePos.y << std::endl; // print mouse position

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
        ~Game() {
            delete window;
            delete player;
        }
};
#endif