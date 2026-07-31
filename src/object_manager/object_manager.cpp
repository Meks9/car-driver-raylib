#include "object_manager.h"

#include <memory>

#include "config.h"
// #include "objects/entity/bird/bird.h"
// #include "objects/entity/tree/tree.h"

void ObjectManager::clearLists(){
    enemyList.clear();
    objectList.clear();
}

void ObjectManager::createObjects(){
    for (int i = 0; i != Config::enemyCount; i++){
        Enemy enemy = Enemy();
        objectManager.enemyList.push_back(enemy);
    }

    // for (int i = 0; i < 1; i++){
    //     createObject<Bird>();
    // }

    // for (int i = 0; i < Config::treeCount; i++){
    //     createObject<Tree>();
    // }
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

    for (std::unique_ptr<Base>& obj : objectList){
        obj->updateDrawing();
    }
}

ObjectManager objectManager = ObjectManager();