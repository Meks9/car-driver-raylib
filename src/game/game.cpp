#include <climits>
#include <raylib.h>
#include "game.h"
#include "config.h"

#include "objects/enemy/enemy.h"
#include "objects/player/player.h"

#include "object_manager/object_manager.h"
#include "ui_manager/ui_manager.h"
#include "collision_manager/collision_manager.h"

void Game::init(){
    SetTargetFPS(Config::targetFps);
    SetRandomSeed(GetRandomValue(1, INT_MAX));

    Player* player = objectManager.getPlayer();
    player->position = Vector2(800, 300);
    player->loadTexture();

    for (int i = 0; i != Config::roadLanesCount; i++){
        int roadCenter = 72;
        int firstLane = (Config::screenWidth / 2) - roadCenter;
        Vector2 newSpawnPoint = Vector2(firstLane + roadCenter * i, -100);

        game.carSpawnPoints.push_back(newSpawnPoint);
    }

    Enemy* en = objectManager.createObject<Enemy>();
    objectManager.removeObject(en);

    game.startGame();
}

void Game::startGame(){
    objectManager.getPlayer()->position = (Vector2((float)Config::screenWidth / 2, (float)Config::screenHeight - 80));

    objectManager.createEnemies();
}

void Game::gameLogic(){
    float frameTime = GetFrameTime();

    if (IsKeyPressed(KEY_P) && !(uiManager.isStartMenuOpen() || uiManager.isEndMenuOpen())) game.togglePause();
    if (IsKeyPressed(KEY_R)) game.resetGame();

    if (Game::isPaused) return;

    SetTargetFPS(Config::targetFps);
    Game::timeCounter += frameTime;

    objectManager.updateObjects(frameTime);

    collisionManager.checkPlayerCollisions();
}

void Game::resetGame(){
    Game::timeCounter = 0.0;

    objectManager.clearLists();

    Game::startGame();
}

Game game = Game();