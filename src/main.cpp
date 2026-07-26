#include <raylib.h>
#include "config.h"

#include "game/game.h"
#include "drawing_manager/drawing_manager.h"

int main(){
    InitWindow(Config::screenWidth, Config::screenHeight, "Car Driver");

    game.init();
    drawingManager.init();

    while (!WindowShouldClose()){
        game.gameLogic();
        drawingManager.gameDrawing();
    }

    CloseWindow();
}