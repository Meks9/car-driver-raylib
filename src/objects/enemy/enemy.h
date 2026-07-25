#pragma once

#include <climits>
#include <raylib.h>
#include "config.h"
#include "game/game.h"
#include "objects/base/base.h"
#include <iostream>
#include <thread>

class Enemy : public Base{
public:
    Enemy(){
        std::string path = Config::sourceDir + "/assets/car1.png";
        Image image = LoadImage(path.c_str());
        ImageRotate(&image, 180);
        ImageResize(&image, 64, 64);
        texture = LoadTextureFromImage(image);
        UnloadImage(image);

        direction = Vector2(position.x, 1);
    }
    Vector2 position;
    Vector2 velocity;
    Vector2 direction;

    const float speed = 240.0f;

    Texture2D texture;
    int spawnTriggerPoint = 100;

    void update(float delta) override {
        velocity.x = direction.x * speed;
        velocity.y = direction.y * speed;

        position.x += velocity.x * delta;
        position.y += velocity.y * delta;

        if (position.y > Config::screenHeight + spawnTriggerPoint) placeAtRandomSpawn();
    }

    void updateDrawing() override {
        DrawTexture(texture, position.x - texture.width / 2.0, position.y - texture.height / 2.0, WHITE);
    }

    void placeAtRandomSpawn(){
        int randLane = GetRandomValue(0, Config::roadLinesCount - 1);

        int xRandomOffset = GetRandomValue(-25, 25);
        int yRandomOffset = GetRandomValue(-25, 25);

        Vector2 point = Game::carSpawnPoints[randLane];
        // point.x += xRandomOffset;
        // point.y += yRandomOffset;

        position = point;

        spawnTriggerPoint = GetRandomValue(50, 350);
    }
};