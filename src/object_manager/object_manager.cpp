#include "object_manager.h"

#include <memory>

#include "objects/base/base.h"
#include "config.h"

void ObjectManager::createEnemies(){
    for (int i = 0; i != Config::enemyCount; i++){
        std::cout << "CREATING " << i << '\n';

        Enemy enemy = Enemy();
        enemy.name = "Enemy" + std::to_string(i);
        std::cout << enemy.name << '\n';
        objectManager.enemyList.push_back(enemy);
    }
}

void ObjectManager::updateObjects(float delta){
    player->update(delta);
    for (Enemy& enemy : enemyList){
        enemy.update(delta);
    }

    for (std::unique_ptr<Base>& obj : objectList){
        obj->update(delta);
    }
}

void ObjectManager::updateDrawingObjects(){
    player->updateDrawing();
    for (Enemy& enemy : enemyList){
        enemy.updateDrawing();
    }
}

ObjectManager objectManager = ObjectManager();