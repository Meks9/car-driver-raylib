#pragma once

#include <raylib.h>
#include <string>

class Base {
public:
    virtual ~Base() = default; 

    int uid;
    std::string name;

    virtual void update(float delta) {};
    virtual void updateDrawing() {};
};
