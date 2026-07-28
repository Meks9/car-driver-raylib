#include "vectorMath.h"

#include <cmath>
#include <raylib.h>

Vector2 VectorMath::normalizeVector2(Vector2 v){
    if (v.x == 0.0 && v.y == 0.0) return Vector2(0,0);

    float length = std::sqrt(v.x * v.x + v.y * v.y);
    Vector2 vNormalized = Vector2(v.x / length, v.y / length);

    return vNormalized;
}