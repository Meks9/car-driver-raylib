#pragma once

#include <raylib.h>
#include <vector>

namespace Game{
    inline Texture2D roadTexture;
    inline std::vector<Vector2> carSpawnPoints = {};

    void init();
    void gameLogic();
    void gameDrawing();   
}