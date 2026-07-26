#pragma once

#include <raylib.h>
#include "config.h"
#include "game/game.h"
#include "objects/base/base.h"
#include "image_loader/image_loader.h"

class Enemy : public Base{
public:
    Enemy(){
        loadTexture();
        placeAtRandomSpawn();
        direction = Vector2(0, 1);
    }

    const float speed = 240.0f;

    Vector2 position;
    Vector2 velocity;
    Vector2 direction;

    Texture2D texture;
    int spawnOffset = -100;

    bool isColliding = false;
    Rectangle collisionRect = Rectangle(0, 0, 40, 40);

    void loadTexture(){
        std::string path = Config::sourceDir + "/assets/car1.png";
        texture = ImageLoader::loadTexture(path.c_str());
    }

    void update(float delta) override {
        velocity.x = direction.x * speed;
        velocity.y = direction.y * speed;

        position.x += velocity.x * delta;
        position.y += velocity.y * delta;

        collisionRect.x = position.x - collisionRect.width / 2;
        collisionRect.y = position.y - collisionRect.height / 2;

        if (position.y > Config::screenHeight) placeAtRandomSpawn();
    }

    void updateDrawing() override {
        DrawTexture(texture, position.x - texture.width / 2.0, position.y - texture.height / 2.0, WHITE);
        DrawRectangleRec(collisionRect, RED);
    }

    void placeAtRandomSpawn(){
        int randLane = GetRandomValue(0, Config::roadLanesCount - 1);

        Vector2 point = Game::carSpawnPoints[randLane];
        spawnOffset = GetRandomValue(-350, -50);    
        point.y += spawnOffset;
        position = point;  
    }
};