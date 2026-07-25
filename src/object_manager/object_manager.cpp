#include "object_manager.h"

void ObjectManager::updateObjects(float delta){
    for (auto& obj : objectList){
        obj->update(delta);
    }
}

void ObjectManager::updateDrawingObjects(){
    for (auto& obj : objectList){
        obj->updateDrawing();
    }
}