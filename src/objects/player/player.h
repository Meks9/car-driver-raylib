#pragma once

#include <cstddef>
#include <raylib.h>
#include <string>
#include "config.h"
#include "objects/base/base.h"
#include "image_loader/image_loader.h"
#include <iostream>

class Player : public Base {
public:
    Player(){position = Vector2(800, 300);}

    const float speed = 240.0f;

    Vector2 position;
    Vector2 velocity;
    Vector2 direction;

    Texture2D texture;

    bool hitWall = false;
    bool hitEnemy = false;
    Rectangle collisionRect = Rectangle(0, 0, 40, 40);

    void loadTexture(){
        std::string path = Config::sourceDir + "/assets/car1.png";
        texture = ImageLoader::loadTexture(path.c_str());
    }

    Vector2 getInputVector(){
        Vector2 input = Vector2();
        if (IsKeyDown(KEY_A)) input.x -= 1;
        if (IsKeyDown(KEY_D)) input.x += 1;

        return input;
    }

    void update(float delta) override {
        direction = getInputVector();
        velocity.x = direction.x * speed;
        velocity.y = direction.y * speed;

        position.x += velocity.x * delta;
        position.y += velocity.y * delta;

        collisionRect.x = position.x - collisionRect.width / 2;
        collisionRect.y = position.y - collisionRect.height / 2;
    }

    void updateDrawing() override {
        DrawTexture(texture, position.x - texture.width / 2.0, position.y - texture.height / 2.0, WHITE);
        DrawRectangleRec(collisionRect, BLUE);
    }
};