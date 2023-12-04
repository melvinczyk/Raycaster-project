#include "Player.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include <SFML/Graphics.hpp>

Player::Player(Map* gameMap) : map(gameMap) {
    initialize();
}

void Player::initialize() {
    x = Settings::PLAYER_POS_X;
    y = Settings::PLAYER_POS_Y;
    angle = Settings::PLAYER_ANGLE;
}

double Player::getAngle(){
    return angle;
}

void Player::setGameWindow(sf::RenderWindow& window)
{
    gameWindow = &window;
}

void Player::movement() {
    double sinA = sin(angle);
    double cosA = cos(angle);
    double dx = 0, dy = 0;
    double speed = Settings::PLAYER_SPEED;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        dx += speed * cosA;
        dy += speed * sinA;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        dx += -speed * cosA;
        dy += -speed * sinA;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        dx += speed * sinA;
        dy += -speed * cosA;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        dx += -speed * sinA;
        dy += speed * cosA;
    }

    checkWallCollision(dx, dy);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        angle -= Settings::PLAYER_ROT_SPEED;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        angle += Settings::PLAYER_ROT_SPEED;
    }

    angle = fmod(angle, M_PI * 2);
}

void Player::checkWallCollision(double dx, double dy) {
    if (!map->checkWall(static_cast<int>(x + dx), static_cast<int>(y))) {
        x += dx;
    }
    if (!map->checkWall(static_cast<int>(x), static_cast<int>(y + dy))) {
        y += dy;
    }
}

void Player::update() {
    movement();
}

sf::Vector2f Player::getPos() {
    return sf::Vector2f(x, y);
}

sf::Vector2i Player::getMapPos() {
    return sf::Vector2i(static_cast<int>(x), static_cast<int>(y));
}
