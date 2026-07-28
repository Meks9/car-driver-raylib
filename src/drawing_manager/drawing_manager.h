#pragma once

#include <raylib.h>

class DrawingManager{
private:
    Texture2D innerRoadTexture;
    Texture2D leftRoadTexture;
    Texture2D rightRoadTexture;
    Texture2D* currentTexture;

    bool showInfo = true;

public:
    const int roadWidth = 72;

    void toggleShowInfo() {showInfo = !showInfo;}
    
    void init();
    void drawInfo();
    void drawRoad();
    void gameDrawing();
    
    int getRoadLeftCorner();
    int getRoadRightCorner();
};

extern DrawingManager drawingManager;