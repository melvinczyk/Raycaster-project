#pragma once

#include <SFML/Graphics.hpp>
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"
#include "Settings.h"
#include "Map.h"

class Player {
public:
    Player(Map* gameMap);
    Player(sf::RenderWindow* window, Map* map);
    void initialize();
    void setPosition(const sf::Vector2f& position);
    void movement();
    void checkWallCollision(double dx, double dy);
    void update();
    double getAngle();
    void setGameWindow(sf::RenderWindow& window);
    sf::RenderWindow* gameWindow;

    sf::Vector2f getPos();
    sf::Vector2i getMapPos();

private:
    Map* map;
    double x, y;
    double angle;

};
