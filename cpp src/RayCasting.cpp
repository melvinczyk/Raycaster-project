#include "RayCasting.h"
#include "SFML/System/Vector2.hpp"
#include "SFML/include/SFML/Graphics.hpp"

RayCasting::RayCasting(Player* gamePlayer, Map* gameMap) : player(gamePlayer), map(gameMap) {}

void RayCasting::rayCast() {
    float ox = player->getPos().x;
    float oy = player->getPos().y;
    int xMap = player->getMapPos().x;
    int yMap = player->getMapPos().y;

    double rayAngle = player->getAngle() - Settings::HALF_FOV + 0.0001;

    for (int ray = 0; ray < Settings::NUM_RAYS; ++ray) {
        double sinA = sin(rayAngle);
        double cosA = cos(rayAngle);

        // Horizontal
        double yHor, dy;
        if (sinA > 0) {
            yHor = yMap + 1;
            dy = 1;
        } else {
            yHor = yMap - 1e-6;
            dy = -1;
        }

        double depthHor = (yHor - oy) / sinA;
        double xHor = ox + depthHor * cosA;

        double deltaDepth = dy / sinA;
        double dx = deltaDepth * cosA;

        for (int i = 0; i < Settings::MAX_DEPTH; ++i) {
            int tileHorX = (int)(xHor);
            int tileHorY = (int)(yHor);

            if (map->checkWall(tileHorX, tileHorY)) {
                break;
            }

            xHor += dx;
            yHor += dy;
            depthHor += deltaDepth;
        }

        // Vertical
        double xVert, dxVert;
        if (cosA > 0) {
            xVert = xMap + 1;
            dxVert = 1;
        } else {
            xVert = xMap - 1e-6;
            dxVert = -1;
        }

        double depthVert = (xVert - ox) / cosA;
        double yVert = oy + depthVert * sinA;

        double deltaDepthVert = dxVert / cosA;
        double dyVert = deltaDepthVert * sinA;

        for (int i = 0; i < Settings::MAX_DEPTH; ++i) {
            int tileVertX = (int)(xVert);
            int tileVertY = (int)(yVert);

            if (map->checkWall(tileVertX, tileVertY)) {
                break;
            }

            xVert += dxVert;
            yVert += dyVert;
            depthVert += deltaDepthVert;
        }

        // Depth
        double depth;
        if (depthVert < depthHor) {
            depth = depthVert;
        } else {
            depth = depthHor;
        }

        // Remove fishbowl effect
        depth *= cos(player->getAngle() - rayAngle);

        // Projecting
        double projHeight = Settings::SCREEN_DIST / (depth + 0.0001);



        // Draw walls
        sf::RectangleShape wall(sf::Vector2f(Settings::SCALE, projHeight));
        wall.setPosition(sf::Vector2f(ray * Settings::SCALE, Settings::HALF_HEIGHT - projHeight / 2));
        wall.setFillColor(sf::Color(255, 255, 255));


        player->gameWindow->draw(wall);

        rayAngle += Settings::DELTA_ANGLE;
    }
}

void RayCasting::update() {
    rayCast();
}
