#include <SFML/Graphics.hpp>
#include "modules/Game.h"

int main() {
    Game g(500, "Combat Game");
    g.run();
    return 0;
}