cmake_minimum_required(VERSION 3.12)
project(game VERSION 2.3.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


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

file(
    GLOB sys_SRC
    "src/mysys/*.hpp"
    "src/mysys/*.cpp"
)

add_library(tinyPTC ${tinyPTC_SRC})
target_link_libraries(tinyPTC X11)
add_library(picoPNG ${picoPNG_SRC})
add_library(mysysLIB ${sys_SRC})


target_include_directories(tinyPTC PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/libs")
target_include_directories(picoPNG PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/libs")
target_include_directories(mysysLIB PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")

add_executable(game src/main.cpp)
target_link_libraries(game PRIVATE tinyPTC picoPNG mysysLIB)
target_link_libraries(mysysLIB PRIVATE tinyPTC)
