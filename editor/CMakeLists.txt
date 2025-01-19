cmake_minimum_required(VERSION 3.16)

project(editor LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE EDITOR_SRC "src/*.cpp" "src/*.c")
file(GLOB_RECURSE EDITOR_INCLUDE "include/*.h" "include/*.hpp")

include_directories(${CMAKE_SOURCE_DIR}/editor/include)

add_executable(editor ${EDITOR_SRC} ${EDITOR_INCLUDE})

# SFML
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)
target_link_libraries(editor sfml-system sfml-window sfml-graphics sfml-audio)

# imgui
find_package(ImGui REQUIRED)
target_link_libraries(editor imgui)
