#pragma once

#include <raylib.h>

namespace ImageLoader {
    Texture2D loadTexture(const char* path);
    Texture2D loadTextureRotate(const char* path, int degrees);
}