#pragma once

#include <memory>
#include <raylib.h>
#include <vector>

#include "objects/entity/enemy/enemy.h"

struct RoadLane{
    int roadWidth;
    Vector2 spawnPoint;
    int turnFreePoint; // Y axis
    bool isFree = true; // can enemy use it to tp itself to it
    Enemy* latestUser;
};

using RoadLanesVector = std::vector<std::unique_ptr<RoadLane>>;

class Game{
private:
    RoadLanesVector roadLanes;
    bool isPaused = false;
    float timeCounter = 0.0f;
    float bestTime = 0.0f;

    const float speedAdditionMultiplier = 2.5f;
    float moveSpeed = 0.0f;

public:
    float getMoveSpeed() {return moveSpeed;}
    float getTimeCounter() {return timeCounter;}

    float getBestTime() {return bestTime;}
    void togglePause() {isPaused = !isPaused;}
    void pauseGame() {isPaused = true;}
    void unpauseGame() {isPaused = false;}

    void setupRoad();
    RoadLane* getRandomFreeLane();
    int getLaneIndex(RoadLane* lane);
    RoadLane* getLane(int index);
    void setBestTime(float newTime);
    
    void init();
    void keyListen();
    void startGame();
    void gameLogic();
    void resetGame(); 
};

extern Game game;
