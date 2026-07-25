#include <climits>
#include <raylib.h>
#include <string>
#include "game.h"
#include "object_manager/object_manager.h"
#include "config.h"
#include "objects/player/player.h"
#include "objects/enemy/enemy.h"

void Game::init(){
    SetTargetFPS(Config::targetFps);
    SetRandomSeed(GetRandomValue(1, INT_MAX));

    Player* player = ObjectManager::createObject<Player>();
    player->position = Vector2((float)Config::screenWidth / 2, (float)Config::screenHeight - 80);
    player->name = "player";

    // Road texture
    std::string path = Config::sourceDir + "/assets/road1.png";
    Image image = LoadImage(path.c_str());
    Game::roadTexture = LoadTextureFromImage(image);
    UnloadImage(image);

    for (int i = 0; i != Config::roadLinesCount; i++){
        int roadCenter = 72;
        int firstLane = (Config::screenWidth / 2) - roadCenter;
        Vector2 newSpawnPoint = Vector2(firstLane + roadCenter * i, -100);

        Game::carSpawnPoints.push_back(newSpawnPoint);
    }

    for (int i = 1; i != 4; i++){
        Enemy* enemy = ObjectManager::createObject<Enemy>();
        enemy->name = "Enemy" + std::to_string(i);
        enemy->placeAtRandomSpawn();
    }
}

void Game::gameLogic(){
    SetTargetFPS(Config::targetFps);

    float frameTime = GetFrameTime();

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

    const char* fpsText;
    fpsText = TextFormat("FPS: %i (Target: %i)", GetFPS(), Config::targetFps);
    DrawText(TextFormat("FPS: %i ", GetFPS()), 10, 10, 20, DARKGRAY);

    drawRoad();

    ObjectManager::updateDrawingObjects();

    EndDrawing();
}

