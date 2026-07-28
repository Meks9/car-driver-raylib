#pragma once

#include <raylib.h>
#include <vector>

#include "config.h"

class CollisionManager{
private:
    const int hWallHeight = Config::screenHeight;
    const int vWallHeight = 10;

    int hWallWidth;
    int vWallWidth;

    Rectangle wallRectLeft;
    Rectangle wallRectRight;

    Rectangle wallRectUp;
    Rectangle wallRectDown;

    std::vector<Rectangle> hWalls;
    std::vector<Rectangle> vWalls;

public:
    void init();
    void createWalls();
    void checkPlayerCollisions();
};

extern CollisionManager collisionManager;