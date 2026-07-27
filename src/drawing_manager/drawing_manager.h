#pragma once

#include <raylib.h>

class DrawingManager{
private:
    Texture2D innerRoadTexture;
    Texture2D leftRoadTexture;
    Texture2D rightRoadTexture;
    Texture2D* currentTexture;

public:
    void init();
    void drawRoad();
    void gameDrawing();
    int getRoadLeftCorner();
    int getRoadRightCorner();
};

extern DrawingManager drawingManager;