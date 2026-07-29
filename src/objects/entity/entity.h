#pragma once

#include <raylib.h>

#include "objects/base/base.h"

class Entity : public Base {
public:
    Entity(){}

    ~Entity() = default; 
    
    Vector2 direction;
    Vector2 velocity;
    Vector2 position;

    Texture2D texture;

    virtual void loadTexture() {};
};