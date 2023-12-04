#include <SFML/Graphics.hpp>
#include <cmath>
#include "Settings.h"
#include "Player.h"
#include "Map.h"

class RayCasting {
public:
    RayCasting(Player* gamePlayer, Map* gameMap);
    void rayCast();
    void update();

private:
    Player* player;
    Map* map;
};
