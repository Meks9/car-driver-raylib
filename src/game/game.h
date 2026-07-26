#pragma once

#include <raylib.h>
#include <vector>

class Game{
private:
    std::vector<Vector2> carSpawnPoints;

    bool isPaused = false;
    float timeCounter = 0.0f;

public:
    float getTimeCounter() {return timeCounter;}
    std::vector<Vector2> getCarSpawns() {return carSpawnPoints;}
    void togglePause() {isPaused = !isPaused;}
    void pauseGame() {isPaused = true;}
    void unpauseGame() {isPaused = false;}
    void init();
    void startGame();
    void gameLogic();
    void resetGame(); 
};

extern Game game;
