#include "objects/entity/bird/bird.h"
#include <raylib.h>
#include <string>

#include "config.h"
#include "image_loader/image_loader.h"

void Bird::loadTexture(){
    std::string path = Config::sourceDir + "/assets/bird1.png";
    texture = ImageLoader::loadTextureRotate(path.c_str(), -90);
}

void Bird::update(float delta){
    velocity.x = direction.x * speed;

    position.x += velocity.x * delta;
    position.y += velocity.y * delta;

    if (position.x < GetRandomValue(-350, -100)) position = getRandomSpawn();
}

void Bird::updateDrawing(){
    DrawTexture(texture, position.x - texture.width / 2.0, position.y - texture.height / 2.0, WHITE);
}