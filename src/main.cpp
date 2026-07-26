#include <raylib.h>
#include "config.h"
#include "game/game.h"

int main(){
    InitWindow(Config::screenWidth, Config::screenHeight, "Car Driver");

    game.init();

    while (!WindowShouldClose()){
        game.gameLogic();
        drawingManager.gameDrawing();
    }

    CloseWindow();
}