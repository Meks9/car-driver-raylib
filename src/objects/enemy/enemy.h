#pragma once

#include <raylib.h>
#include "game/game.h"
#include "objects/base/base.h"

#include <iostream>

class Enemy : public Base{
private:
    const float SPEED_ADDITION_MULTIPLIER = 2.1f;
    const float speed = 240.0f;
public:
    Enemy(){
        std::cout << "CONSTRUCT\n";
        loadTexture();
        placeAtRandomSpawn();
        direction = Vector2(0, 1);
    }

    Vector2 position;
    Vector2 velocity;
    Vector2 direction;

    Texture2D texture;
    Vector2 spawnOffset = Vector2(0, -100);

    bool isColliding = false;
    Rectangle collisionRect = Rectangle(0, 0, 24, 40);

    RoadLane* currentLane = nullptr;

    void loadTexture();
    void placeAtRandomSpawn();

    void update(float delta) override;
    void updateDrawing() override;
};