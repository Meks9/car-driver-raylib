#include "drawing_manager.h"

#include "config.h"
#include "image_loader/image_loader.h"
#include "object_manager/object_manager.h"
#include "game/game.h"
#include <raylib.h>

void DrawingManager::init(){
    std::string path;
    path = Config::sourceDir + "/assets/innerRoad.png";
    drawingManager.innerRoadTexture = ImageLoader::loadTexture(path.c_str());

    path = Config::sourceDir + "/assets/leftRoad.png";
    drawingManager.leftRoadTexture = ImageLoader::loadTexture(path.c_str());

    path = Config::sourceDir + "/assets/rightRoad.png";
    drawingManager.rightRoadTexture = ImageLoader::loadTexture(path.c_str());
}

void DrawingManager::drawRoad(){
    int xStart = (Config::screenWidth / 2) - (leftRoadTexture.width * Config::roadLanesCount / 2);
    int xPos;
    int yCurrentSize;

    int doneLines = 0;

    for (int i = 0; i < Config::roadLanesCount; i++){
        if (doneLines == 0) currentTexture = &leftRoadTexture;
        else if (doneLines == Config::roadLanesCount - 1) currentTexture = &rightRoadTexture;
        else currentTexture = &innerRoadTexture;

        yCurrentSize = 0;
        xPos = xStart + (i * currentTexture->width);
        while (yCurrentSize < Config::screenHeight){
            DrawTexture(*currentTexture, xPos, yCurrentSize, WHITE);
            yCurrentSize += currentTexture->height;
        }
        doneLines++;
    }
}

void DrawingManager::gameDrawing(){
    BeginDrawing();

    ClearBackground(Color(80, 160, 10));

    DrawText(TextFormat("FPS: %i ", GetFPS()), 10, 10, 20, DARKGRAY);
    DrawText(TextFormat("Time: %.2f ", game.getTimeCounter()), 10, 30, 20, DARKGRAY);
    DrawText(TextFormat("Move with:\nWASD or Arrows"), 10, 50, 20, DARKGRAY);
    DrawText(TextFormat("Move slower:\nShift"), 10, 90, 20, DARKGRAY);


    drawRoad();

    objectManager.updateDrawingObjects();

    EndDrawing();
}

int DrawingManager::getRoadLeftCorner(){
    return (Config::screenWidth / 2) - (leftRoadTexture.width * Config::roadLanesCount / 2);
}
int DrawingManager::getRoadRightCorner(){
    return (Config::screenWidth / 2) + (leftRoadTexture.width * Config::roadLanesCount / 2);
}

DrawingManager drawingManager = DrawingManager();