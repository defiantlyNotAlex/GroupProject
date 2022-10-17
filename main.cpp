#include <SFML/Graphics.hpp>
#include "modules/Game.h"

int main() {
    // initialize game
    Game g(500, "Rock Paper Scissor Combat");
    // run game
    g.run();
    return 0;
}