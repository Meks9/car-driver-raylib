#pragma once

#include "objects/enemy/enemy.h"
#include <memory>
#include <raylib.h>
#include <vector>


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

    bool isPaused = false;
    float timeCounter = 0.0f;

public:
    RoadLanesVector roadLanes;
    float getTimeCounter() {return timeCounter;}
    RoadLane* getLane(int index);
    void togglePause() {isPaused = !isPaused;}
    void pauseGame() {isPaused = true;}
    void unpauseGame() {isPaused = false;}
    void setupRoad();
    RoadLane* getRandomFreeLane();
    int getLaneIndex(RoadLane* lane);
    void init();
    void startGame();
    void gameLogic();
    void resetGame(); 
};

extern Game game;
