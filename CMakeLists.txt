cmake_minimum_required(VERSION 3.12)
project(game VERSION 2.3.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



file(
    GLOB tinyPTC_SRC
    "src/libs/tinyPTC/*.h"
    "src/libs/tinyPTC/*.c"
)
add_library(tinyPTC ${tinyPTC_SRC})
target_link_libraries(tinyPTC X11)
target_include_directories(tinyPTC PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/libs")



file(
    GLOB picoPNG_SRC
    "src/libs/picoPNG/*.hpp"
    "src/libs/picoPNG/*.cpp"
)
add_library(picoPNG ${picoPNG_SRC})
target_include_directories(picoPNG PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/libs")



file(
    GLOB mysysLIB_SRC
    "src/mysys/*.hpp"
    "src/mysys/*.cpp"
)
add_library(mysysLIB ${mysysLIB_SRC})
target_link_libraries(mysysLIB PRIVATE tinyPTC)
target_include_directories(mysysLIB PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")



file(
    GLOB mymanLIB_SRC
    "src/myman/*.hpp"
    "src/myman/*.cpp"
)
add_library(mymanLIB ${mymanLIB_SRC})
target_include_directories(mymanLIB PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/man")


add_executable(game src/main.cpp)
target_link_libraries(game PRIVATE tinyPTC picoPNG mysysLIB)
