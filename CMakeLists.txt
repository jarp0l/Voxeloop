include(FetchContent)
cmake_minimum_required(VERSION 3.17)

project(voxeloop)

set(CMAKE_CXX_STANDARD 17)

set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(
        voxeloop-base
        GIT_REPOSITORY https://github.com/RujalAcharya/voxeloop-base.git
        GIT_TAG main
)
FetchContent_MakeAvailable(voxeloop-base)

include_directories(include)

add_executable(voxeloop src/main.cpp)

target_link_libraries(
        voxeloop
        imgui
        glm
)