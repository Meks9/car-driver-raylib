#include <raylib.h>
#include "enemy.h"

#include "game/game.h"
#include "config.h"
#include "image_loader/image_loader.h"

void Enemy::loadTexture(){
    std::string path = Config::sourceDir + "/assets/car1.png";
    Enemy::texture = ImageLoader::loadTextureRotate(path.c_str(), 180);
}

void Enemy::placeAtRandomSpawn(){
    RoadLane* lane = game.getRandomFreeLane();
    Vector2 point;

    if (lane == nullptr) {
        point = noLineSpawn;
        position = point;
        return;
    }

    laneIndex = game.getLaneIndex(lane);
    point = lane->spawnPoint;
    lane->isFree = false;
    lane->latestUser = this;

    spawnOffset = Vector2(GetRandomValue(-20, 20), GetRandomValue(-350, -50));

    point.x += spawnOffset.x;
    point.y += spawnOffset.y;
    position = point;  
}

void Enemy::update(float delta){
    velocity.x = direction.x * speed;
    velocity.y = direction.y * speed + (game.getTimeCounter() * speedAdditionMultiplier);

    position.x += velocity.x * delta;
    position.y += velocity.y * delta;

    collisionRect.x = position.x - collisionRect.width / 2;
    collisionRect.y = position.y - collisionRect.height / 2;

    RoadLane* lane = game.getLane(laneIndex);

    if (lane != nullptr && lane->latestUser == this){
        if (position.y > lane->turnFreePoint) lane->isFree = true;
    }
    if (position.y > Config::screenHeight + 50) placeAtRandomSpawn();
}

void Enemy::updateDrawing(){
    DrawTexture(texture, position.x - texture.width / 2.0, position.y - texture.height / 2.0, WHITE);
    //DrawRectangleRec(collisionRect, RED);
}

