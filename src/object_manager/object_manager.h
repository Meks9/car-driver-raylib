#pragma once

#include <raylib.h>
#include <vector>
#include <memory>

#include "objects/base/base.h"

namespace ObjectManager{
    inline std::vector<std::unique_ptr<Base>> objectList = {};

    // Create object of given class and returns regular ptr to it
    template<typename T>
    T* createObject(){
        std::unique_ptr<T> newObj = std::make_unique<T>();
        objectList.push_back(std::move(newObj));
        return static_cast<T*>(objectList.back().get());
    }

    // template<typename T>
    // T* addObject(std::unique_ptr<T> obj){
    //     objectList.push_back(std::move(obj));
    //     return static_cast<T*>(objectList.back().get());
    // }

    template<typename T>
    void removeObject(T& targetObj){
        for (int i = 0; i < objectList.size(); i++){
            if (objectList[i].get() == targetObj) objectList.erase(objectList.end() - i);
        }
    }

    template<typename T>
    T* getObjectByName(std::string name){
        for (std::unique_ptr<Base>& obj : objectList){
            if (obj->name == name) return static_cast<T*>(obj.get());
        }
        return nullptr;
    }

    void updateObjects(float delta);
    void updateDrawingObjects();

};