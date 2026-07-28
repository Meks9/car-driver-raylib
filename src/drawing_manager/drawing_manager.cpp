#include "drawing_manager.h"

#include <raylib.h>

#include "config.h"
#include "image_loader/image_loader.h"
#include "game/game.h"
#include "object_manager/object_manager.h"

void DrawingManager::init(){
    std::string path;
    path = Config::sourceDir + "/assets/innerRoad.png";
    drawingManager.innerRoadTexture = ImageLoader::loadTexture(path.c_str());

    path = Config::sourceDir + "/assets/leftRoad.png";
    drawingManager.leftRoadTexture = ImageLoader::loadTexture(path.c_str());

    path = Config::sourceDir + "/assets/rightRoad.png";
    drawingManager.rightRoadTexture = ImageLoader::loadTexture(path.c_str());
}

void DrawingManager::drawInfo(){
    DrawText(TextFormat("Time: %.2f ", game.getTimeCounter()), 10, 10, 20, DARKGRAY);
    DrawText(TextFormat("Best time: %.2f ", game.getBestTime()), 10, 30, 20, DARKGRAY);

    if (!showInfo) return;
    
    DrawText(TextFormat("Move with:\nWASD or Arrows"), 10, 120, 20, DARKGRAY);
    DrawText(TextFormat("Move slower:\nShift"), 10, 160, 20, DARKGRAY);

    DrawText(TextFormat("Reset game: R"), 10, 200, 20, DARKGRAY);

    DrawText(TextFormat("Increase/Deacrease\nroad lanes: U/J"), 10, 230, 20, DARKGRAY);
    DrawText(TextFormat("Current: %i", Config::roadLanesCount), 10, 270, 20, DARKGRAY);

    DrawText(TextFormat("Increase/Deacrease\ncar count: I/K"), 10, 310, 20, DARKGRAY);
    DrawText(TextFormat("Current: %i", Config::enemyCount), 10, 350, 20, DARKGRAY);

    DrawText(TextFormat("Hide/Show text: O"), 10, 380, 20, DARKGRAY);
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

    ClearBackground(Config::bgColor);

    drawRoad();
    objectManager.updateDrawingObjects();
    drawInfo();

    EndDrawing();
}

int DrawingManager::getRoadLeftCorner(){
    return (Config::screenWidth / 2) - (leftRoadTexture.width * Config::roadLanesCount / 2);
}
int DrawingManager::getRoadRightCorner(){
    return (Config::screenWidth / 2) + (leftRoadTexture.width * Config::roadLanesCount / 2);
}

DrawingManager drawingManager = DrawingManager();