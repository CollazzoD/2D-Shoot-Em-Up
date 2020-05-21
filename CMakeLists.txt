cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_STANDARD 17)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(2D-Shoot-Em-Up)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} src)

add_executable(2D-Shoot-Em-Up src/main.cpp src/renderer.cpp src/controller.cpp src/game.cpp src/player.cpp src/entity.cpp src/bullet.cpp src/enemy.cpp src/alienBullet.cpp)
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(2D-Shoot-Em-Up ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
