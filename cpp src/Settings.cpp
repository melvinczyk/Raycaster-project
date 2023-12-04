#include "Settings.h"

const double Settings::FPS = 0.0;
const double Settings::PLAYER_POS_X = 1.5;
const double Settings::PLAYER_POS_Y = 5.0;
const double Settings::PLAYER_ANGLE = 0.0;
const double Settings::PLAYER_SPEED = 0.004;
const double Settings::PLAYER_ROT_SPEED = 0.002;
const double Settings::FOV = M_PI / 3;
const double Settings::HALF_FOV = FOV / 2;
const int Settings::NUM_RAYS = WIDTH / 2;
const int Settings::HALF_NUM_RAYS = NUM_RAYS / 2;
const double Settings::DELTA_ANGLE = FOV / NUM_RAYS;
const int Settings::MAX_DEPTH = 20;
const double Settings::SCREEN_DIST = HALF_WIDTH / tan(HALF_FOV);
const int Settings::SCALE = WIDTH / NUM_RAYS;
