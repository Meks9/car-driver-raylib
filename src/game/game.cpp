#include <raylib.h>
#include <memory>
#include "game.h"
#include "object_manager/object_manager.h"
#include "config.h"
#include "objects/player/player.h"
#include "objects/enemy/enemy.h"

void Game::init(){
    SetTargetFPS(Config::targetFps);

    std::unique_ptr<Player> player = std::make_unique<Player>();
    player->position = Vector2((float)Config::screenWidth / 2, (float)Config::screenHeight - 80);
    player->name = "player";
    ObjectManager::objectList.push_back(std::move(player));
    Enemy* enemy1 = ObjectManager::createObject<Enemy>();
    enemy1->position = Vector2((float)Config::screenWidth / 2 + 100, (float)Config::screenHeight / 2);
}

void Game::gameLogic(){
    SetTargetFPS(Config::targetFps);

    float frameTime = GetFrameTime();

    float mouseWheel = GetMouseWheelMove();

    ObjectManager::updateObjects(frameTime);
}

void Game::gameDrawing(){
    BeginDrawing();

    ClearBackground(RAYWHITE);

    const char* fpsText;
    fpsText = TextFormat("FPS: %i (Target: %i)", GetFPS(), Config::targetFps);
    DrawText(TextFormat("FPS: %i ", GetFPS()), 10, 10, 20, DARKGRAY);

    DrawRectangle(Config::screenWidth / 2 - 100, 0, 200, Config::screenHeight, BLACK);

    ObjectManager::updateDrawingObjects();

    EndDrawing();
}

