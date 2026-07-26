cmake_minimum_required(VERSION 3.14)
project(car-driver)

set(CMAKE_CXX_STANDARD 20)

add_executable(car-driver main.cpp
    config.h
    
    game/game.cpp
    game/game.h
    collision_manager/collision_manager.h
    collision_manager/collision_manager.cpp
    drawing_manager/drawing_manager.cpp
    drawing_manager/drawing_manager.h
    object_manager/object_manager.cpp
    object_manager/object_manager.h
    ui_manager/ui_manager.cpp
    ui_manager/ui_manager.h
    image_loader/image_loader.cpp
    image_loader/image_loader.h
    
    objects/base/base.h
    objects/player/player.cpp
    objects/player/player.h
    objects/enemy/enemy.cpp
    objects/enemy/enemy.h)

find_package(raylib 2.0 REQUIRED)
target_link_libraries(car-driver raylib)

target_include_directories(car-driver PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

