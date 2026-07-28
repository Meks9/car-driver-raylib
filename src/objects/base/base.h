#pragma once

#include <raylib.h>

class Base {
public:
    Base() {}
    ~Base() = default; 

    virtual void update(float delta) {};
    virtual void updateDrawing() {};
};
