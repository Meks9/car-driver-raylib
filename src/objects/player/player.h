#pragma once

#include <raylib.h>
#include "objects/base/base.h"

class Player : public Base {
private:
    const float speed = 240.0f;

    Texture2D texture;
public:
    Player(){}
    
    Vector2 position;
    Vector2 velocity;
    Vector2 direction;

    bool hitWall = false;
    bool hitEnemy = false;
    Rectangle collisionRect = Rectangle(0, 0, 26, 40);

    void loadTexture();
    Vector2 getInputVector();

    void update(float delta) override;
    void updateDrawing() override;
};