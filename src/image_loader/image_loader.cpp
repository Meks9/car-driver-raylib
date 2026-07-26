#include "image_loader.h"
#include <raylib.h>

Texture2D ImageLoader::loadTexture(const char* path){
    Image image = LoadImage(path);
    Texture2D texture = LoadTextureFromImage(image);
    UnloadImage(image);

    return texture;
}
