#pragma once

#include <raylib.h>
#include <vector>

//#include "objects/base/base.h"
#include "objects/player/player.h"
#include "objects/enemy/enemy.h"

namespace ObjectManager{
    //extern std::vector<std::unique_ptr<Base>> objectList;
    extern Player player;
    extern std::vector<Enemy> enemyList;

    extern int wallWidth;
    extern Rectangle wallRectLeft;
    extern Rectangle wallRectRight;
    extern std::vector<Rectangle> walls;

    void init();
    void updateObjects(float delta);
    void updateDrawingObjects();

};