#include "Map.h"

Map::Map() {
    initialize();
}

void Map::initialize() {
    miniMap = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1},
        {1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    getMap();
}

void Map::getMap() {
    int mapSize = miniMap.size();
    for (int j = 0; j < mapSize; ++j) {
        int rowSize = miniMap[j].size();
        for (int i = 0; i < rowSize; ++i) {
            if (miniMap[j][i] == 1) {
                worldMap.push_back(sf::Vector2i(i, j));
            }
        }
    }
}

void Map::draw(sf::RenderWindow& window) {
    for (const sf::Vector2i& pos : worldMap) {
        sf::RectangleShape wall(sf::Vector2f(Settings::SCALE, Settings::SCALE));
        wall.setPosition(sf::Vector2f(pos.x * Settings::SCALE, pos.y * Settings::SCALE));
        wall.setFillColor(sf::Color::White);
        window.draw(wall);
    }
}

bool Map::checkWall(int x, int y) const {
    return std::find(worldMap.begin(), worldMap.end(), sf::Vector2i(x, y)) != worldMap.end();
}
