cmake_minimum_required(VERSION 3.10)
project(CGame)

set(CMAKE_CXX_STANDARD 11)

add_executable(CGame ExampleGame.cpp Sprite.cpp Sprite.h MovingSprite.h PlayerSprite.h GUI.h GUI.cpp GameEngine.cpp GameEngine.h NPCSprite.cpp NPCSprite.h MovingSprite.cpp)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR})

find_package(SDL2 REQUIRED)

find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIR}
${SDL2_IMAGE_INCLUDE_DIR}
${SDL2TTF_INCLUDE_DIR})
target_link_libraries(CGame ${SDL2_LIBRARY}
${SDL2_IMAGE_LIBRARIES}
${SDL2_TTF_LIBRARY})

