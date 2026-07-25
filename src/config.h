#pragma once

#include <filesystem>
#include <string>

namespace Config {
    inline int targetFps = 60;
    inline int screenWidth = 800;
    inline int screenHeight = 450;
    inline const std::string sourceDir = std::filesystem::path(__FILE__).parent_path().string();
}