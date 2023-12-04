# pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "settings.h"

class Map {
public:
    Map();
    void initialize();
    void getMap();
    void draw(sf::RenderWindow& window);
    bool checkWall(int x, int y) const;

private:
    std::vector<std::vector<int>> miniMap;
    std::vector<sf::Vector2i> worldMap;
};
