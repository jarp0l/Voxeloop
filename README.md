# Voxeloop

### Musical Loop Generation in Voxel World

[![.github/workflows/docs.yml](https://github.com/jarp0l/Voxeloop/actions/workflows/docs.yml/badge.svg)](https://github.com/jarp0l/Voxeloop/actions/workflows/docs.yml)

## Documentation

Complete online documentation of the project is available at: 
[https://jarp0l.github.io/Voxeloop](https://jarp0l.github.io/Voxeloop)

## Build

**Build using CMake**

If you have ninja installed

```sh
    mkdir build
    cd build
    cmake .. -G Ninja
    ninja
    ./voxeloop
```

Alternatively

```sh
    mkdir build
    cd build
    cmake
    make
    ./voxeloop
```

**Note:** Since the project was developed mainly on linux machines, it is not guaranteed that the project will build on first time at Windows. You may need to change the paths of assets used to the relative path. Also since the libraries are built from source, it takes a bit longer time when building for the first time.

## Project By

* Prajwol Pradhan (PUL076BEI023)
* Rujal Acharya (PUL076BEI029)

## Libraries Used

* GLFW: [https://glfw.org/](https://glfw.org/)
* GLAD: [https://github.com/Dav1dde/glad](https://github.com/Dav1dde/glad)
* Dear ImGui: [https://github.com/ocornut/imgui](https://github.com/ocornut/imgui)
* stb: [https://github.com/nothings/stb](https://github.com/nothings/stb)
* miniaudio: [https://miniaud.io/](https://miniaud.io/)

## Screenshots of Program

### Menu Screen

![menu](screenshots/menu.png)

### About Screen

![about](screenshots/about.png)

### Settings Screen

![menu](screenshots/settings.png)

### Play Screen

![play](screenshots/main.png)