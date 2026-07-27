#include <climits>
#include <memory>
#include <raylib.h>
#include <vector>
#include "game.h"
#include "config.h"

#include "objects/player/player.h"

#include "object_manager/object_manager.h"
#include "ui_manager/ui_manager.h"
#include "collision_manager/collision_manager.h"
#include "drawing_manager/drawing_manager.h"

void Game::setupRoad(){
    for (int i = 0; i != Config::roadLanesCount; i++){
        std::unique_ptr<RoadLane> newLane = std::make_unique<RoadLane>();

        newLane->isFree = true;
        newLane->roadWidth = 72;
        newLane->spawnPoint = Vector2(drawingManager.getRoadLeftCorner() + (i * 72) + (newLane->roadWidth / 2.0), -50);
        newLane->turnFreePoint = 0;

        game.roadLanes.push_back(std::move(newLane));
    }
}

RoadLane* Game::getLane(int index){
    for (int i = 0; i < roadLanes.size(); i++){
        if (i == index) return roadLanes[i].get();
    }
    return nullptr;
}

RoadLane* Game::getRandomFreeLane(){
    std::vector<RoadLane*> freeLanes = {};
    for (int i = 0; i < roadLanes.size(); i++){
        RoadLane* lane = roadLanes[i].get();
        if (lane->isFree) freeLanes.push_back(lane);
    }

    if (freeLanes.size() == 0) return nullptr;

    int rand = GetRandomValue(0, freeLanes.size() - 1);
    
    return freeLanes[rand];
}

int Game::getLaneIndex(RoadLane* lane){
    for (int i = 0; i < roadLanes.size(); i++){
        if (roadLanes[i].get() == lane) return i;
    }

    return -1;
}

void Game::init(){
    SetTargetFPS(Config::targetFps);
    SetRandomSeed(GetRandomValue(1, INT_MAX));

    Player* player = objectManager.getPlayer();
    player->position = Vector2(800, 300);
    player->loadTexture();
}

void Game::startGame(){
    setupRoad();

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

    collisionManager.createWalls();
    collisionManager.checkPlayerCollisions();
}

void Game::resetGame(){
    Game::timeCounter = 0.0;

    objectManager.clearLists();
    roadLanes.clear();

    game.startGame();
}

Game game = Game();