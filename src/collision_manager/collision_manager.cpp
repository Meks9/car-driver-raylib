#include "collision_manager.h"

#include "object_manager/object_manager.h"
#include "drawing_manager/drawing_manager.h"

void CollisionManager::createWalls(){
    hWallWidth = drawingManager.getRoadLeftCorner();
    vWallWidth = Config::screenWidth;

    wallRectLeft = Rectangle(0, 0, hWallWidth, hWallHeight);
    wallRectRight = Rectangle(drawingManager.getRoadRightCorner(), 0, hWallWidth, hWallHeight);

    wallRectUp = Rectangle(0, 0, vWallWidth, vWallHeight);
    wallRectDown = Rectangle(0, Config::screenHeight, vWallWidth, vWallHeight);

    hWalls = {wallRectLeft, wallRectRight};
    vWalls = {wallRectUp, wallRectDown};
}

void CollisionManager::checkPlayerCollisions(){
    Player* player = objectManager.getPlayer();

    for (Enemy& enemy : objectManager.getEnemyList()){
        player->hitEnemy = CheckCollisionRecs(player->collisionRect, enemy.collisionRect);
        //if (player->hitEnemy) game.resetGame();
    }

    for (Rectangle& wall : hWalls){
        player->hitWall = CheckCollisionRecs(player->collisionRect, wall);
        if (!player->hitWall) continue;

        Rectangle rect = GetCollisionRec(player->collisionRect, wall);
        
        if (player->direction.x > 0.0) player->position.x -= rect.width;
        else player->position.x += rect.width;

        break;
    }

    for (Rectangle& wall : vWalls){
        player->hitWall = CheckCollisionRecs(player->collisionRect, wall);
        if (!player->hitWall) continue;

        Rectangle rect = GetCollisionRec(player->collisionRect, wall);
        
        if (player->direction.y > 0.0) player->position.y -= rect.height;
        else player->position.y += rect.height;
        
        break;
    }
}

CollisionManager collisionManager = CollisionManager();