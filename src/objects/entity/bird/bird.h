#pragma once

#include <raylib.h>

#include "config.h"
#include "objects/entity/entity.h"

class Bird : public Entity{
private:

public:
    Bird(){
        loadTexture();
        position = getRandomSpawn();
        //position = Vector2(Config::screenWidth + 100, GetRandomValue(300, 500));
        direction = Vector2(-1, 0);
    }

    ~Bird() = default; 

    const float speed = 440.0f;

    Vector2 getRandomSpawn() {return Vector2(Config::screenWidth + 100, GetRandomValue(50, Config::screenHeight - 50));}

    void loadTexture() override;
    void update(float delta) override;
    void updateDrawing() override;
};