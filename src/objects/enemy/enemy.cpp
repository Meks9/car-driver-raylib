#include <raylib.h>
#include "enemy.h"

#include "game/game.h"
#include "config.h"
#include "image_loader/image_loader.h"

void Enemy::update(float delta) {
    velocity.x = direction.x * speed;
    velocity.y = direction.y * speed + (game.getTimeCounter() * SPEED_ADDITION_MULTIPLIER);

    position.x += velocity.x * delta;
    position.y += velocity.y * delta;

    collisionRect.x = position.x - collisionRect.width / 2;
    collisionRect.y = position.y - collisionRect.height / 2;

    if (position.y > Config::screenHeight) placeAtRandomSpawn();
}

void Enemy::loadTexture(){
    std::string path = Config::sourceDir + "/assets/car1.png";
    Enemy::texture = ImageLoader::loadTexture(path.c_str());
}

void Enemy::placeAtRandomSpawn(){
    int randLane = GetRandomValue(0, Config::roadLanesCount - 1);

    Vector2 point = game.getCarSpawns()[randLane];
    spawnOffset = Vector2(GetRandomValue(-15, 15), GetRandomValue(-350, -50));

    point.x += spawnOffset.x;
    point.y += spawnOffset.y;
    position = point;  
}


