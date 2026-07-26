#pragma once

#include <raylib.h>
#include <vector>
#include "config.h"

class CollisionManager{
private:
    const int hWallHeight = Config::screenHeight;
    const int vWallHeight = 10;

    int hWallWidth = Config::screenWidth / 2 - 128;
    int vWallWidth = Config::screenWidth;

    Rectangle wallRectLeft = Rectangle(0, 0, hWallWidth, hWallHeight);
    Rectangle wallRectRight = Rectangle(Config::screenWidth - hWallWidth, 0, hWallWidth, hWallHeight);

    Rectangle wallRectUp = Rectangle(0, 0, vWallWidth, vWallHeight);
    Rectangle wallRectDown = Rectangle(0, Config::screenHeight, vWallWidth, vWallHeight);

    std::vector<Rectangle> hWalls = {wallRectLeft, wallRectRight};
    std::vector<Rectangle> vWalls = {wallRectUp, wallRectDown};

public:
    void checkPlayerCollisions();
};

extern CollisionManager collisionManager;