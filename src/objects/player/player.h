#pragma once

#include <raylib.h>

#include "config.h"
#include "objects/base/base.h"

class Player : public Base {
private:
    Vector2 velocity;
    Vector2 direction;

    Texture2D texture;
    Rectangle collisionRect = Rectangle(0, 0, 26, 52);

public:
    Player(){
        position = defaultPos;
    }

    ~Player() = default; 
    
    const float speed = 240.0f;
    const Vector2 defaultPos = Vector2(Config::screenWidth / 2.0, Config::screenHeight - 80);
    
    Vector2 position;

    bool hitWall = false;
    bool hitEnemy = false;

    Rectangle getCollisionRect() {return collisionRect;}
    Vector2 getdirection() {return direction;}

    void loadTexture();
    Vector2 getInputVector();

    void update(float delta) override;
    void updateDrawing() override;
};