#include <SFML/Graphics.hpp>
#include "modules/Game.h"
#include "modules/Sprite.h"
#include <iostream>
#include <string>
// test
void test(bool result, std::string testName) {
    if (!result) {
        std::cout << "Test failed: " << testName << std::endl;
    }
}
int main() {
    // Game g(500, "Rock Paper Scissor Combat");
    // g.run();
    // test Sprite class
    // test saveAtributes and loadAtributes
    {
        Sprite *sprite;
        sprite = new Sprite(1, 50, 10, 1, 100);
        int attributes[8] = {20, 20, 3, 50, 20, 1, 100, 120};
        sprite.loadAtributes(attributes);
        bool res = sprite.saveAtributes() == attributes;
        test(res, "Sprite load and save attributes");
    }
    return 0;
}