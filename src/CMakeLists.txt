cmake_minimum_required(VERSION 3.14)
project(car-driver)

set(CMAKE_CXX_STANDARD 20)

add_executable(car-driver main.cpp
    config.h
    math/vectorMath.h
    math/vectorMath.cpp
    
    game/game.cpp
    game/game.h
    collision_manager/collision_manager.h
    collision_manager/collision_manager.cpp
    drawing_manager/drawing_manager.cpp
    drawing_manager/drawing_manager.h
    object_manager/object_manager.cpp
    object_manager/object_manager.h
    image_loader/image_loader.cpp
    image_loader/image_loader.h
    
    objects/base/base.h
    objects/entity/entity.h
    objects/entity/player/player.cpp
    objects/entity/player/player.h
    objects/entity/enemy/enemy.cpp
    objects/entity/enemy/enemy.h
    objects/entity/bird/bird.cpp
    objects/entity/bird/bird.h
    objects/entity/tree/tree.h
    objects/entity/tree/tree.cpp
    )

find_package(raylib 2.0 REQUIRED)
target_link_libraries(car-driver raylib)

target_include_directories(car-driver PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})