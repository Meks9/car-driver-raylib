#pragma once

class UIManager{
private:
    bool startMenuOpen = false;
    bool endMenuOpen = false;

public:
    bool isStartMenuOpen() {return startMenuOpen;}
    bool isEndMenuOpen() {return endMenuOpen;}
    void showStartMenu();
    void showEndMenu();
};

extern UIManager uiManager;