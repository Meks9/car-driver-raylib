#pragma once

#include <raylib.h>

#include "objects/base/base.h"

class Enemy : public Base{
private:
    Vector2 velocity;
    Vector2 direction;
    Vector2 spawnOffset = Vector2(0, -100);

    Texture2D texture;
    Rectangle collisionRect = Rectangle(0, 0, 26, 52);
public:
    Enemy(){
        loadTexture();
        position = Vector2(-50, GetRandomValue(300, 500));
        direction = Vector2(0, 1);
    }

    ~Enemy() = default; 

    const Vector2 noLineSpawn = Vector2(-50, 500);
    const float speedAdditionMultiplier = 2.5f;
    const float speed = 240.0f;

    Vector2 position;
    int laneIndex = -1;

    Rectangle getCollisionRect() {return collisionRect;}

    void loadTexture();
    void placeAtRandomSpawn();

    void update(float delta) override;
    void updateDrawing() override;
};