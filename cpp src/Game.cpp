#include <SFML/Window.hpp>
#include <SFML/System/Vector2.hpp>
#include "Game.h"
#include <string>
/* #include "player.h" */

Game::Game(const sf::Vector2u& windowSize) : window(sf::VideoMode({windowSize.x, windowSize.y}), "Raycasting"), deltaTime(1), map(), player(&window, &map), rayCasting(&player, &map) {
    newGame();
}

void Game::newGame() {
    player = Player(&window,&map);
    map.initialize();
}

void Game::update() {
    player.update();
    rayCasting.update();
    window.display();
    deltaTime = clock.restart().asSeconds();
    window.setTitle(std::to_string(1 / deltaTime));
}

void Game::draw() {
    window.clear(sf::Color::Black);
    window.display();
}

void Game::checkEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
            window.close();
        }
    }
}

void Game::run() {
    while (window.isOpen()) {
        checkEvents();
        update();
        draw();
    }
}
