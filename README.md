# Voxelloop

### Setting Up Project

**Installing GLFW**

```sh
    sudo apt install libglfw3 libglfw3-dev
```

or use similar commands based on your distro

**Installing GLAD**

```sh
    git clone https://github.com/Dav1dde/glad.git
    cd glad
    cmake ./
    make
    sudo cp -a include /usr/local/
```

**Build using cmake**