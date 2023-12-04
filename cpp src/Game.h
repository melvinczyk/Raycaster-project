#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include "Map.h"
#include "Player.h"
#include "RayCasting.h"
#include "Settings.h"

class Game {
public:
    Game(const sf::Vector2u& windowSize);
    void run();

private:
    sf::RenderWindow window;
    sf::Clock clock;
    float deltaTime;
    Map map;
    Player player;
    RayCasting rayCasting;

    void newGame();
    void update();
    void draw();
    void checkEvents();
};
