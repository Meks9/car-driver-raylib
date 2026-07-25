#pragma once

#include <raylib.h>
#include <string>
#include "config.h"
#include "objects/base/base.h"

class Player : public Base {
public:
    Player(){
        std::string path = Config::sourceDir + "/assets/car1.png";
        Image image = LoadImage(path.c_str());
        ImageResize(&image, 64, 64);
        texture = LoadTextureFromImage(image);
        UnloadImage(image);
    }

    Vector2 position;
    Vector2 velocity;
    Vector2 direction;

    const float speed = 240.0f;
    const float width = 50.0f;

    Texture2D texture;

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
    }

    void updateDrawing() override {
        DrawCircleV(position, 40, PURPLE);

        DrawTexture(texture, position.x - texture.width / 2.0, position.y - texture.height / 2.0, WHITE);
    }
};