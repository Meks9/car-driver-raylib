#include "object_manager.h"

#include <memory>

#include "config.h"

void ObjectManager::createEnemies(){
    for (int i = 0; i != Config::enemyCount; i++){
        Enemy enemy = Enemy();
        objectManager.enemyList.push_back(enemy);
    }
}

void ObjectManager::updateObjects(float delta){
    player->update(delta);
    for (Enemy& enemy : enemyList){
        enemy.update(delta);
    }
}

void ObjectManager::updateDrawingObjects(){
    player->updateDrawing();
    for (Enemy& enemy : enemyList){
        enemy.updateDrawing();
    }
}

ObjectManager objectManager = ObjectManager();