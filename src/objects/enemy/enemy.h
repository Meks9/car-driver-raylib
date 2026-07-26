#pragma once

#include <raylib.h>
#include "objects/base/base.h"

class Enemy : public Base{
public:
    Enemy(){
        loadTexture();
        placeAtRandomSpawn();
        direction = Vector2(0, 1);
    }

    const float SPEED_ADDITION_MULTIPLIER = 2.1f;
    const float speed = 240.0f;

    Vector2 position;
    Vector2 velocity;
    Vector2 direction;

    Texture2D texture;
    Vector2 spawnOffset = Vector2(0, -100);

    bool isColliding = false;
    Rectangle collisionRect = Rectangle(0, 0, 40, 40);

    void update(float delta) override;

    void updateDrawing() override {
        DrawTexture(texture, position.x - texture.width / 2.0, position.y - texture.height / 2.0, WHITE);
        DrawRectangleRec(collisionRect, RED);
    }

    void loadTexture();
    void placeAtRandomSpawn();
};