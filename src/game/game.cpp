#include <climits>
#include <raylib.h>
#include <string>
#include "game.h"
#include "object_manager/object_manager.h"
#include "config.h"
#include "objects/player/player.h"
#include "objects/enemy/enemy.h"
#include "image_loader/image_loader.h"

void Game::init(){
    SetTargetFPS(Config::targetFps);
    SetRandomSeed(GetRandomValue(1, INT_MAX));

    std::string path = Config::sourceDir + "/assets/road1.png";
    Game::roadTexture = ImageLoader::loadTexture(path.c_str());

    for (int i = 0; i != Config::roadLanesCount; i++){
        int roadCenter = 72;
        int firstLane = (Config::screenWidth / 2) - roadCenter;
        Vector2 newSpawnPoint = Vector2(firstLane + roadCenter * i, -100);

        Game::carSpawnPoints.push_back(newSpawnPoint);
    }

    ObjectManager::player.loadTexture();
    ObjectManager::player.position = Vector2((float)Config::screenWidth / 2, (float)Config::screenHeight - 80);
    ObjectManager::player.name = "player";

    for (int i = 0; i != Config::enemyCount; i++){
        Enemy enemy = Enemy();
        enemy.name = "Enemy" + std::to_string(i);
        ObjectManager::enemyList.push_back(enemy);
    }
}

void Game::gameLogic(){
    float frameTime = GetFrameTime();

    if (IsKeyPressed(KEY_P)) Game::isPaused = !Game::isPaused;

    if (Game::isPaused) return;

    SetTargetFPS(Config::targetFps);
    Game::timeCounter += frameTime;

    ObjectManager::updateObjects(frameTime);
}

void drawRoad(){
    int xPos = (Config::screenWidth / 2) - (Game::roadTexture.width / 2);
    int yTotalSize = 0;

    while (yTotalSize < Config::screenHeight){
        DrawTexture(Game::roadTexture, xPos, yTotalSize, WHITE);
        yTotalSize += Game::roadTexture.height;
    }
    
}

void Game::gameDrawing(){
    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText(TextFormat("FPS: %i ", GetFPS()), 10, 10, 20, DARKGRAY);
    DrawText(TextFormat("Time: %.2f ", Game::timeCounter), 10, 30, 20, DARKGRAY);

    drawRoad();

    ObjectManager::updateDrawingObjects();

    EndDrawing();
}

