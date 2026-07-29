#pragma once

#include <raylib.h>

#include "config.h"
#include "objects/entity/entity.h"

class Player : public Entity {
private:
    Rectangle collisionRect = Rectangle(0, 0, 26, 52);

public:
    Player(){
        position = defaultPos;
    }

    ~Player() = default; 
    
    const float speed = 240.0f;
    const Vector2 defaultPos = Vector2(Config::screenWidth / 2.0, Config::screenHeight - 80);
    
    bool hitWall = false;
    bool hitEnemy = false;

    Rectangle getCollisionRect() {return collisionRect;}

    Vector2 getInputVector();

    void loadTexture() override;
    void update(float delta) override;
    void updateDrawing() override;
};