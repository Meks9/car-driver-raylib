#include <climits>
#include <memory>
#include <raylib.h>
#include <vector>

#include "config.h"

#include "game.h"
#include "object_manager/object_manager.h"
#include "collision_manager/collision_manager.h"
#include "drawing_manager/drawing_manager.h"

#include "objects/entity/player/player.h"

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
RoadLane* Game::getLane(int index){
    for (int i = 0; i < roadLanes.size(); i++){
        if (i == index) return roadLanes[i].get();
    }
    return nullptr;
}

void Game::setBestTime(float newTime){
    if (newTime > bestTime) bestTime = newTime;
}

void Game::init(){
    SetTargetFPS(Config::targetFps);
    SetRandomSeed(GetRandomValue(1, INT_MAX));

    Player* player = objectManager.getPlayer();
    player->loadTexture();
}


void Game::keyListen(){
    if (IsKeyPressed(KEY_R)) game.resetGame();

    if (IsKeyPressed(KEY_U)) {
        Config::roadLanesCount++;
        resetGame();
    }
    if (IsKeyPressed(KEY_J) && Config::roadLanesCount > 1){
        Config::roadLanesCount--;
        resetGame();
    }

    if (IsKeyPressed(KEY_I)){
        Config::enemyCount++;
        resetGame();
    }
    if (IsKeyPressed(KEY_K) && Config::enemyCount > 0){
        Config::enemyCount--;
        resetGame();
    }

    if (IsKeyPressed(KEY_P)) Config::hideTrees = !Config::hideTrees;

    if (IsKeyPressed(KEY_O)) drawingManager.toggleShowInfo();
}

void Game::startGame(){
    setupRoad();
    collisionManager.init();

    Player* player = objectManager.getPlayer();
    player->position = player->defaultPos;

    objectManager.createObjects();
}

void Game::gameLogic(){
    float frameTime = GetFrameTime();

    keyListen();

    if (isPaused) return;

    SetTargetFPS(Config::targetFps);
    timeCounter += frameTime;
    moveSpeed = game.getTimeCounter() * speedAdditionMultiplier;

    objectManager.updateObjects(frameTime);

    collisionManager.checkPlayerCollisions();
}

void Game::resetGame(){
    setBestTime(timeCounter);
    timeCounter = 0.0;

    objectManager.clearLists();
    roadLanes.clear();

    game.startGame();
}

Game game = Game();