#include "tree.h"

#include <raylib.h>
#include <string>

#include "config.h"
#include "drawing_manager/drawing_manager.h"
#include "image_loader/image_loader.h"

#include "game/game.h"

void Tree::loadTexture(){
    std::string carVariation = std::to_string(GetRandomValue(1, Config::carVariations));
    std::string path = Config::sourceDir + "/assets/tree1.png";
    Tree::texture = ImageLoader::loadTexture(path.c_str());
}

void Tree::placeAtRandomSpawn(){
    float firstRand = GetRandomValue(0, drawingManager.getRoadLeftCorner() - 50);
    float secRand = GetRandomValue(drawingManager.getRoadRightCorner() + 50,Config::screenWidth);
    float randChoice = (GetRandomValue(0, 1) == 0) ? firstRand : secRand;

    Vector2 point = Vector2(randChoice, GetRandomValue(-Config::screenHeight, -50));
    position = point;  
}

void Tree::update(float delta){
    velocity.x = direction.x * speed;
    velocity.y = direction.y * speed + game.getMoveSpeed();

    position.x += velocity.x * delta;
    position.y += velocity.y * delta;

    RoadLane* lane = game.getLane(laneIndex);

    if (position.y > Config::screenHeight + 50) placeAtRandomSpawn();
}

void Tree::updateDrawing(){
    if (Config::hideTrees) return;
    DrawTexture(texture, position.x - texture.width / 2.0, position.y - texture.height / 2.0, WHITE);
}

