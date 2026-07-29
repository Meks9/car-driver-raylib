#include "enemy.h"

#include <raylib.h>
#include <string>

#include "config.h"
#include "image_loader/image_loader.h"

#include "game/game.h"

void Enemy::loadTexture(){
    std::string carVariation = std::to_string(GetRandomValue(1, Config::carVariations));
    std::string path = Config::sourceDir + "/assets/car" + carVariation + ".png";
    Enemy::texture = ImageLoader::loadTextureRotate(path.c_str(), 180);
}

void Enemy::placeAtRandomSpawn(){
    RoadLane* lane = game.getRandomFreeLane();

    if (lane == nullptr) {
        position = noLineSpawn;
        return;
    }

    Vector2 point;

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
    velocity.y = direction.y * speed + game.getMoveSpeed();

    position.x += velocity.x * delta;
    position.y += velocity.y * delta;

    collisionRect.x = position.x - collisionRect.width / 2;
    collisionRect.y = position.y - collisionRect.height / 2;

    RoadLane* lane = game.getLane(laneIndex);

    if (lane != nullptr && lane->latestUser == this && position.y > lane->turnFreePoint) lane->isFree = true;
    if (position.y > Config::screenHeight + 50) placeAtRandomSpawn();
}

void Enemy::updateDrawing(){
    DrawTexture(texture, position.x - texture.width / 2.0, position.y - texture.height / 2.0, WHITE);
    //DrawRectangleRec(collisionRect, RED);
}

