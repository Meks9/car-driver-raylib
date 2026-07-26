#pragma once

#include <raylib.h>
#include <vector>
#include <memory>

#include "objects/base/base.h"
#include "objects/player/player.h"
#include "objects/enemy/enemy.h"

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

extern ObjectManager objectManager;