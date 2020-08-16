cmake_minimum_required(VERSION 3.12)
project(game VERSION 2.3.0)

file(
    GLOB tinyPTC_SRC
    "src/libs/tinyPTC/*.h"
    "src/libs/tinyPTC/*.c"
)

file(
    GLOB picoPNG_SRC
    "src/libs/picoPNG/*.hpp"
    "src/libs/picoPNG/*.cpp"
)

add_library(tinyPTC ${tinyPTC_SRC})
add_library(picoPNG ${picoPNG_SRC})


target_include_directories(tinyPTC PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/libs")
target_include_directories(picoPNG PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/libs")

add_executable(game src/main.cpp)
target_link_libraries(game PRIVATE tinyPTC picoPNG X11)
