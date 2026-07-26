#pragma once

#include <memory>
#include <raylib.h>
#include <vector>

#include "objects/base/base.h"
#include "objects/player/player.h"
#include "objects/enemy/enemy.h"

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

class DrawingManager{
private:
    Texture2D roadTexture;

public:
    void drawRoad();
    void gameDrawing();
};

using ObjectList = std::vector<std::unique_ptr<Base>>;

class ObjectManager{
private:
    std::unique_ptr<Player> player = std::make_unique<Player>();
    std::vector<Enemy> enemyList = {};
    ObjectList objectList; // used for objects that dont have their own list

public:
    Player* getPlayer() {return player.get();}
    void clearLists() {enemyList.clear();}
    std::vector<Enemy> getEnemyList() {return enemyList;}
    ObjectList* getObjectList() {return &objectList;}
    void createEnemies();
    void updateObjects(float delta);
    void updateDrawingObjects();

    template<typename T>
    T* createObject(){
        std::unique_ptr<T> newObj = std::make_unique<T>();
        objectList.push_back(std::move(newObj));
        return static_cast<T*>(objectList.back().get());
    }

    template<typename T>
    void removeObject(T* targetObj){
        for (int i = 0; i < objectList.size(); i++){
            if (objectList[i].get() == targetObj) objectList.erase(objectList.begin() + i);
        }
    }

};

class UIManager{
private:
    bool startMenuOpen = false;
    bool endMenuOpen = false;

public:
    bool isStartMenuOpen() {return startMenuOpen;}
    bool isEndMenuOpen() {return endMenuOpen;}
    void showStartMenu();
    void showEndMenu();
};

class CollisionManager{
private:
    int hWallWidth = Config::screenWidth / 2 - 128;
    int vWallWidth = Config::screenWidth;

    Rectangle wallRectLeft = Rectangle(0, 0, hWallWidth, Config::screenHeight);
    Rectangle wallRectRight = Rectangle(Config::screenWidth - hWallWidth, 0, hWallWidth, Config::screenHeight);
    Rectangle wallRectUp = Rectangle(0, 10, vWallWidth, 10);
    Rectangle wallRectDown = Rectangle(0, Config::screenHeight, vWallWidth, 10);

    std::vector<Rectangle> hWalls = {wallRectLeft, wallRectRight};
    std::vector<Rectangle> vWalls = {wallRectUp, wallRectDown};

public:
    void checkPlayerCollisions();
};

extern Game game;
extern DrawingManager drawingManager;
extern ObjectManager objectManager;
extern UIManager uiManager;
extern CollisionManager collisionManager;

