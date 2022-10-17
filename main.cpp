#include <SFML/Graphics.hpp>
#include "modules/Game.h"
#include "tests.h" 
int main() {
    #ifndef TEST
    #define TEST
        tests();
    #endif

    // initialize game
    Game g(500, "Rock Paper Scissor Combat");
    // run game
    g.run();

    
    return 0;
}