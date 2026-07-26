#include <climits>
#include <raylib.h>
#include <string>
#include "game.h"
#include "config.h"
#include "image_loader/image_loader.h"
#include "objects/base/base.h"
#include "objects/enemy/enemy.h"
#include <iostream>

void Game::init(){
    SetTargetFPS(Config::targetFps);
    SetRandomSeed(GetRandomValue(1, INT_MAX));

    Player* player = objectManager.getPlayer();
    player->position = Vector2(800, 300);
    player->loadTexture();

    for (int i = 0; i != Config::roadLanesCount; i++){
        int roadCenter = 72;
        int firstLane = (Config::screenWidth / 2) - roadCenter;
        Vector2 newSpawnPoint = Vector2(firstLane + roadCenter * i, -100);

        game.carSpawnPoints.push_back(newSpawnPoint);
    }

    Enemy* en = objectManager.createObject<Enemy>();
    objectManager.removeObject(en);

    game.startGame();
}

void Game::startGame(){
    objectManager.getPlayer()->position = (Vector2((float)Config::screenWidth / 2, (float)Config::screenHeight - 80));

    objectManager.createEnemies();
}

void Game::gameLogic(){
    float frameTime = GetFrameTime();

    if (IsKeyPressed(KEY_P) && !(uiManager.isStartMenuOpen() || uiManager.isEndMenuOpen())) game.togglePause();
    if (IsKeyPressed(KEY_R)) game.resetGame();

    if (Game::isPaused) return;

    SetTargetFPS(Config::targetFps);
    Game::timeCounter += frameTime;

    objectManager.updateObjects(frameTime);

    collisionManager.checkPlayerCollisions();
}

void Game::resetGame(){
    Game::timeCounter = 0.0;

    objectManager.clearLists();

    Game::startGame();
}

void DrawingManager::drawRoad(){
    std::string path = Config::sourceDir + "/assets/road1.png";
    DrawingManager::roadTexture = ImageLoader::loadTexture(path.c_str());

    int xPos = (Config::screenWidth / 2) - (DrawingManager::roadTexture.width / 2);
    int yTotalSize = 0;

    while (yTotalSize < Config::screenHeight){
        DrawTexture(DrawingManager::roadTexture, xPos, yTotalSize, WHITE);
        yTotalSize += DrawingManager::roadTexture.height;
    }
}

void DrawingManager::gameDrawing(){
    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText(TextFormat("FPS: %i ", GetFPS()), 10, 10, 20, DARKGRAY);
    DrawText(TextFormat("Time: %.2f ", game.getTimeCounter()), 10, 30, 20, DARKGRAY);

    drawRoad();

    objectManager.updateDrawingObjects();

    EndDrawing();
}

void ObjectManager::createEnemies(){
    for (int i = 0; i != Config::enemyCount; i++){
        Enemy enemy = Enemy();
        enemy.name = "Enemy" + std::to_string(i);
        objectManager.enemyList.push_back(enemy);
    }
}

void ObjectManager::updateObjects(float delta){
    player->update(delta);
    for (Enemy& enemy : enemyList){
        enemy.update(delta);
    }
    // for (int i = 0; i < objectList.size(); i++){
    //     objectList[i]->update(delta);
    // }
    for (auto& obj : objectList){
        obj->update(delta);
    }
}

void ObjectManager::updateDrawingObjects(){
    player->updateDrawing();
    for (Enemy& enemy : enemyList){
        enemy.updateDrawing();
    }
}

void UIManager::showStartMenu(){
    uiManager.startMenuOpen = true;
    game.pauseGame();
}

void UIManager::showEndMenu(){
    uiManager.endMenuOpen = true;
    game.pauseGame();
}

void CollisionManager::checkPlayerCollisions(){
    Player* player = objectManager.getPlayer();

    for (Enemy& enemy : objectManager.getEnemyList()){
        player->hitEnemy = CheckCollisionRecs(player->collisionRect, enemy.collisionRect);
        //if (Game::player.hitEnemy) Game::resetGame();
    }

    for (Rectangle& wall : hWalls){
        player->hitWall = CheckCollisionRecs(player->collisionRect, wall);
        if (!player->hitWall) continue;

        Rectangle rect = GetCollisionRec(player->collisionRect, wall);
        
        if (player->position.x > Config::screenWidth / 2.0) player->position.x -= rect.width;
        else player->position.x += rect.width;

        break;
    }

    for (Rectangle& wall : vWalls){
        player->hitWall = CheckCollisionRecs(player->collisionRect, wall);
        if (!player->hitWall) continue;

        Rectangle rect = GetCollisionRec(player->collisionRect, wall);
        
        if (player->position.y > Config::screenHeight / 2.0) player->position.y -= rect.height;
        else player->position.y += rect.height;
        
        break;
    }
}

Game game = Game();
DrawingManager drawingManager = DrawingManager();
ObjectManager objectManager = ObjectManager();
UIManager uiManager = UIManager();
CollisionManager collisionManager = CollisionManager();