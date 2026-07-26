#pragma once

#include <raylib.h>

class DrawingManager{
private:
    Texture2D roadTexture;

public:
    void init();
    void drawRoad();
    void gameDrawing();
};

extern DrawingManager drawingManager;