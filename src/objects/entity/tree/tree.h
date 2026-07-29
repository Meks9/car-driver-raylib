#pragma once

#include <raylib.h>

#include "config.h"
#include "objects/entity/entity.h"

class Tree : public Entity{
private:
    Vector2 spawnOffset = Vector2(0, -100);
public:
    Tree(){
        loadTexture();
        position = noLineSpawn;
        direction = Vector2(0, 1);
    }

    ~Tree() = default; 

    const Vector2 noLineSpawn = Vector2(-100, Config::screenHeight - 100);
    float speed = 240.0f;

    int laneIndex = -1;

    void placeAtRandomSpawn();

    void loadTexture() override;
    void update(float delta) override;
    void updateDrawing() override;
};