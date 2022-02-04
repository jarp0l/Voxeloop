cmake_minimum_required(VERSION 3.21)
project(voxeloop)

set(CMAKE_CXX_STANDARD 17)

add_executable(voxeloop extern/glad.c main.cpp)
target_link_libraries(voxeloop GL GLU glfw X11 Xxf86vm Xrandr pthread Xi dl)

