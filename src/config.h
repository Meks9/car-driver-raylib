#pragma once

#include <filesystem>
#include <string>
#include <raylib.h>

namespace Config {
    inline int targetFps = 60;
    inline int screenWidth = 800;
    inline int screenHeight = 600;
    inline const std::string sourceDir = std::filesystem::path(__FILE__).parent_path().string();
    inline int roadLanesCount = 3;
    inline int enemyCount = 4;
    inline int treeCount = 12;
    inline bool hideTrees = false;
    inline int carVariations = 4;
    inline Color bgColor = Color(80, 160, 10);
}