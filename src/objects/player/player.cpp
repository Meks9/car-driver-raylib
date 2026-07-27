#include <raylib.h>
#include "player.h"
#include "config.h"
#include "image_loader/image_loader.h"

void Player::loadTexture(){
    std::string path = Config::sourceDir + "/assets/car1.png";
    texture = ImageLoader::loadTexture(path.c_str());
}

Vector2 Player::getInputVector(){
    Vector2 input = Vector2();
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) input.y -= 1;
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) input.y += 1;
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) input.x -= 1;
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) input.x += 1;

    if (IsKeyDown(KEY_LEFT_SHIFT)){
        input.x /= 2;
        input.y /= 2;
    }

    return input;
}

void Player::update(float delta){
    direction = getInputVector();
    velocity.x = direction.x * speed;
    velocity.y = direction.y * speed;

    position.x += velocity.x * delta;
    position.y += velocity.y * delta;

    collisionRect.x = position.x - collisionRect.width / 2;
    collisionRect.y = position.y - collisionRect.height / 2;
}

void Player::updateDrawing(){
    DrawTexture(texture, position.x - texture.width / 2.0, position.y - texture.height / 2.0, WHITE);
    //DrawRectangleRec(collisionRect, BLUE);
}

