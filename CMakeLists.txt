cmake_minimum_required(VERSION 3.10)

project(jdl)

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
target_compile_options(${PROJECT_NAME} PRIVATE -O2)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} "C:/Program Files (x86)/SDL2_mixer/include")
target_link_libraries(${PROJECT_NAME} SDL2::SDL2 SDL2::SDL2main SDL2_image::SDL2_image SDL2_mixer::SDL2_mixer)