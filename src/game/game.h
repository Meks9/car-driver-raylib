#pragma once

#include <raylib.h>
#include <vector>

namespace Game{
    inline Texture2D roadTexture;
    inline std::vector<Vector2> carSpawnPoints = {};
    inline bool isPaused = false;
    inline double timeCounter = 0.0;

    void init();
    void gameLogic();
    void gameDrawing();   
}