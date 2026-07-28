#include "image_loader.h"

#include <raylib.h>

Texture2D ImageLoader::loadTexture(const char* path){
    Image image = LoadImage(path);
    Texture2D texture = LoadTextureFromImage(image);
    UnloadImage(image);

    return texture;
}

Texture2D ImageLoader::loadTextureRotate(const char* path, int degrees){
    Image image = LoadImage(path);
    ImageRotate(&image, degrees);
    Texture2D texture = LoadTextureFromImage(image);
    UnloadImage(image);

    return texture;
}
