#include <raylib.h>
#include "enemy.h"

#include "game/game.h"
#include "config.h"
#include "image_loader/image_loader.h"

#include <iostream>

void Enemy::loadTexture(){
    std::string path = Config::sourceDir + "/assets/car1.png";
    Enemy::texture = ImageLoader::loadTextureRotate(path.c_str(), 180);
}

void Enemy::placeAtRandomSpawn(){
    RoadLane* lane = game.getRandomFreeLane();
    std::cout << "CAALLLLLL\n";
    Vector2 point;

    if (lane == nullptr) {
        std::cout << "NULLL\n";
        point = Vector2(0, 0);
        position = point;
        return;
    }
    std::cout << lane->spawnPoint.x << '\n';

    currentLane = lane;
    point = currentLane->spawnPoint;
    currentLane->isFree = false;
    spawnOffset = Vector2(GetRandomValue(-15, 15), GetRandomValue(-350, -50));

    point.x += spawnOffset.x;
    point.y += spawnOffset.y;
    position = point;  
}

void Enemy::update(float delta){
    velocity.x = direction.x * speed;
    velocity.y = direction.y * speed + (game.getTimeCounter() * SPEED_ADDITION_MULTIPLIER);

    position.x += velocity.x * delta;
    position.y += velocity.y * delta;

    collisionRect.x = position.x - collisionRect.width / 2;
    collisionRect.y = position.y - collisionRect.height / 2;
    std::cout << position.y << '\n';

    if (currentLane != nullptr){
        if (position.y > currentLane->turnFreePoint) currentLane->isFree = true;
    }
    if (position.y > Config::screenHeight) placeAtRandomSpawn();
}

void Enemy::updateDrawing(){
    DrawTexture(texture, position.x - texture.width / 2.0, position.y - texture.height / 2.0, WHITE);
    DrawRectangleRec(collisionRect, RED);

    Color col = RED;
    if (currentLane == game.roadLanes[0].get()) col = WHITE;
    if (currentLane == game.roadLanes[1].get()) col = GREEN;
    if (currentLane == game.roadLanes[2].get()) col = BLUE;
    DrawCircle(position.x, position.y, 25.0f, col);
}

