#pragma once

#include <raylib.h>
#include "objects/base/base.h"

class Enemy : public Base{
private:
    const Vector2 noLineSpawn = Vector2(20, 200);
    const float speedAdditionMultiplier = 2.5f;
    const float speed = 240.0f;
public:
    Enemy(){
        loadTexture();
        position = Vector2(noLineSpawn.x, GetRandomValue(-100, 100));
        direction = Vector2(0, 1);
    }

    Vector2 position;
    Vector2 velocity;
    Vector2 direction;

    Texture2D texture;
    Vector2 spawnOffset = Vector2(0, -100);

    bool isColliding = false;
    Rectangle collisionRect = Rectangle(0, 0, 24, 40);

    int laneIndex = -1;

    void loadTexture();
    void placeAtRandomSpawn();

    void update(float delta) override;
    void updateDrawing() override;
};