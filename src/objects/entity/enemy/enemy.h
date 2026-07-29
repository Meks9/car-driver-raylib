#pragma once

#include <raylib.h>

#include "objects/entity/entity.h"

class Enemy : public Entity{
private:
    Vector2 spawnOffset = Vector2(0, -100);
    Rectangle collisionRect = Rectangle(0, 0, 26, 52);
public:
    Enemy(){
        loadTexture();
        position = Vector2(-50, GetRandomValue(300, 500));
        direction = Vector2(0, 1);
    }

    ~Enemy() = default; 

    const Vector2 noLineSpawn = Vector2(-50, 500);
    float speed = 340.0f;

    int laneIndex = -1;

    Rectangle getCollisionRect() {return collisionRect;}

    void placeAtRandomSpawn();

    void loadTexture() override;
    void update(float delta) override;
    void updateDrawing() override;
};