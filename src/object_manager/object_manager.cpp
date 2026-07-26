#include "object_manager.h"
#include "config.h"
#include <raylib.h>

//std::vector<std::unique_ptr<Base>> ObjectManager::objectList = {};
Player ObjectManager::player = Player();
std::vector<Enemy> ObjectManager::enemyList = {};

int ObjectManager::wallWidth = Config::screenWidth / 2 - 128;
Rectangle ObjectManager::wallRectLeft = Rectangle(0, 0, wallWidth, Config::screenHeight);
Rectangle ObjectManager::wallRectRight = Rectangle(Config::screenWidth - wallWidth, 0, wallWidth, Config::screenHeight);
std::vector<Rectangle> ObjectManager::walls = {wallRectLeft, wallRectRight};

void ObjectManager::updateObjects(float delta){
    player.update(delta);
    for (Enemy& enemy : enemyList){
        enemy.update(delta);
    }

    // collision check
    for (Enemy& enemy : enemyList){
        player.hitEnemy = CheckCollisionRecs(player.collisionRect, enemy.collisionRect);
        if (player.hitEnemy) return;
    }

    for (Rectangle& wall : walls){
        player.hitWall = CheckCollisionRecs(player.collisionRect, wall);
        if (player.hitWall) {
            Rectangle rect = GetCollisionRec(player.collisionRect, wall);
            
            if (player.position.x > Config::screenWidth / 2.0) player.position.x -= rect.width;
            else player.position.x += rect.width;
            
            return;
        }
    }

}

void ObjectManager::updateDrawingObjects(){
    player.updateDrawing();
    for (Enemy& enemy : enemyList){
        enemy.updateDrawing();
    }
}