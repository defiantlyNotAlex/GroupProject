#include <SFML/Graphics.hpp>
#include "modules/Game.h"

int main() {
    Game g(500, "Rock Paper Scissor Combat");
    g.run();
    return 0;
}