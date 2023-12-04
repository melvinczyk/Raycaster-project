#include "Game.h"
#include "SFML/System/Vector2.hpp"

int main() {
    sf::Vector2u windowSize(Settings::WIDTH, Settings::HEIGHT);
    Game game(windowSize);
    game.run();

    return 0;
}
