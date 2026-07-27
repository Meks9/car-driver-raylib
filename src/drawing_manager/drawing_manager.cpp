#include "drawing_manager.h"

#include "config.h"
#include "image_loader/image_loader.h"
#include "object_manager/object_manager.h"
#include "game/game.h"

void DrawingManager::init(){
    std::string path = Config::sourceDir + "/assets/road1.png";
    drawingManager.roadTexture = ImageLoader::loadTexture(path.c_str());
}

void DrawingManager::drawRoad(){
    int xPos = (Config::screenWidth / 2) - (DrawingManager::roadTexture.width / 2);
    int yTotalSize = 0;

    while (yTotalSize < Config::screenHeight){
        DrawTexture(DrawingManager::roadTexture, xPos, yTotalSize, WHITE);
        yTotalSize += DrawingManager::roadTexture.height;
    }
}

void DrawingManager::gameDrawing(){
    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText(TextFormat("FPS: %i ", GetFPS()), 10, 10, 20, DARKGRAY);
    DrawText(TextFormat("Time: %.2f ", game.getTimeCounter()), 10, 30, 20, DARKGRAY);

    drawRoad();

    objectManager.updateDrawingObjects();

    EndDrawing();
}

DrawingManager drawingManager = DrawingManager();