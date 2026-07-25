#include <raylib.h>
#include "config.h"
#include "game/game.h"

int main(){
    InitWindow(Config::screenWidth, Config::screenHeight, "Car Driver");

    Game::init();

    while (!WindowShouldClose()){
        Game::gameLogic();
        Game::gameDrawing();
    }

    CloseWindow();
}