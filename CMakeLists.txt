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

add_executable(voxeloop src/shader.cpp src/fileHandler.cpp src/main.cpp src/vbo.cpp src/ebo.cpp src/vao.cpp)

target_link_libraries(
        voxeloop
        glad
        imgui
        glm
)

