#include "player.h"

#include <raylib.h>

#include "config.h"
#include "image_loader/image_loader.h"
#include "math/vectorMath.h"

Vector2 Player::getInputVector(){
    Vector2 input = Vector2();
    
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) input.y -= 1;
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) input.y += 1;
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) input.x -= 1;
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) input.x += 1;

    return input;
}

void Player::loadTexture(){
    std::string path = Config::sourceDir + "/assets/car1.png";
    texture = ImageLoader::loadTexture(path.c_str());
}

void Player::update(float delta){
    direction = getInputVector();
    direction = VectorMath::normalizeVector2(direction);

    if (IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT)){
        direction.x /= 2;
        direction.y /= 2;
    }

    velocity.x = direction.x * speed;
    velocity.y = direction.y * speed;

    position.x += velocity.x * delta;
    position.y += velocity.y * delta;

    // prevent that weird bug which throws player away from map
    if (position.x < 0 || position.x > Config::screenWidth) position = defaultPos;
    else if (position.y < 0 || position.y > Config::screenWidth) position = defaultPos;

    collisionRect.x = position.x - collisionRect.width / 2;
    collisionRect.y = position.y - collisionRect.height / 2;
}

void Player::updateDrawing(){
    DrawTexture(texture, position.x - texture.width / 2.0, position.y - texture.height / 2.0, WHITE);
    //DrawRectangleRec(collisionRect, BLUE);
}

