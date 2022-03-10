# Voxeloop

### Musical Loop Generation in Voxel World

[![.github/workflows/docs.yml](https://github.com/jarp0l/Voxeloop/actions/workflows/docs.yml/badge.svg)](https://github.com/jarp0l/Voxeloop/actions/workflows/docs.yml)

- [Voxeloop](#voxeloop)
    - [Musical Loop Generation in Voxel World](#musical-loop-generation-in-voxel-world)
  - [To-Do](#to-do)
  - [Documentation](#documentation)
  - [Build](#build)
    - [Build using CMake](#build-using-cmake)
      - [With `ninja`](#with-ninja)
      - [With `make`](#with-make)
  - [Project By](#project-by)
  - [Libraries Used](#libraries-used)
  - [Screenshots of Program](#screenshots-of-program)
    - [Menu Screen](#menu-screen)
    - [About Screen](#about-screen)
    - [Settings Screen](#settings-screen)
    - [Play Screen](#play-screen)
- [Acknowledgements](#acknowledgements)

**Course project for 4th sem [BEI II/II] of DSA and Computer Graphics**

## To-Do
This project is still under development. We have planned to do the following things:
- [ ] Implement lighting and shadow in the voxels.
- [ ] Add camera movement.
- [ ] Add actual functionality to the 'Settings' screen, that means the feature to change some settings (music, key bindings) in the program itself.
- [ ] Improve documentation.
- [ ] Move documentation to another branch/repo and auto-generate it based on changes in the `main` branch.


## Documentation
Online documentation of the project is available at: 
[https://jarp0l.github.io/Voxeloop](https://jarp0l.github.io/Voxeloop)


Project report: [VOXELOOP__PRAJWOL_RUJAL_076BEI023_29.pdf](https://github.com/jarp0l/Voxeloop/blob/main/VOXELOOP__PRAJWOL_RUJAL_076BEI023_29.pdf)

## Build
Before proceeding make sure that you have the required dependencies installed. Follow the steps in the official website of GLFW: [Installing dependencies](https://www.glfw.org/docs/latest/compile.html#compile_deps).

### Build using CMake

(*Note: You must be in `build` directory.*)

#### With `ninja`
If you have `ninja` installed:

```sh
    mkdir build
    cd build
    cmake .. -G Ninja
    ninja
    ./voxeloop
```

#### With `make`

```sh
    mkdir build
    cd build
    cmake ..
    make
    ./voxeloop
```

**Note:** Since the project was developed mainly on linux machines, it is not guaranteed that the project will build on first time at Windows. You may need to change the paths of assets used to the relative path. Also since the libraries are built from source, it takes a bit longer time when building for the first time.

## Project By
* Prajwol Pradhan (PUL076BEI023)
* Rujal Acharya (PUL076BEI029)
 
## Libraries Used

* GLFW: [https://glfw.org](https://glfw.org)
* GLAD: [https://github.com/Dav1dde/glad](https://github.com/Dav1dde/glad)
* Dear ImGui: [https://github.com/ocornut/imgui](https://github.com/ocornut/imgui)
* stb: [https://github.com/nothings/stb](https://github.com/nothings/stb)
* miniaudio: [https://miniaud.io](https://miniaud.io)

## Screenshots of Program
### Menu Screen

![menu](screenshots/menu.png)

### About Screen

![about](screenshots/about.png)

### Settings Screen

![menu](screenshots/settings.png)

### Play Screen

![play](screenshots/main.png)

# Acknowledgements
* Ineptic Font by  Chequered Ink (Non-Commercial use)
* Icon font header file by @juliettef: https://github.com/juliettef/IconFontCppHeaders
* Icon font by FontAwesome: https://fontawesome.com
