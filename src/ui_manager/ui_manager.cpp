#include "ui_manager.h"

#include "game/game.h"

void UIManager::showStartMenu(){
    uiManager.startMenuOpen = true;
    game.pauseGame();
}

void UIManager::showEndMenu(){
    uiManager.endMenuOpen = true;
    game.pauseGame();
}

UIManager uiManager = UIManager();