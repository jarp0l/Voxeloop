#include "Voxeloop.hpp"

Voxeloop::Voxeloop() : GLMajor{4}, GLMinor{5} {
  mvmt = 0.0f;
  scale = 1.0f;

  // Initialize Project
  audio = new Audio;
  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GLMajor);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GLMinor);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Setup Window

  window = glfwCreateWindow(WinWidth, WinHeight, "Voxeloop", nullptr, nullptr);

  if (!window) {
    std::cerr << "Couldn't open window" << std::endl;
    glfwTerminate();
    return;
  }
  glfwMakeContextCurrent(window);

  // Load GLAD and setup viewport
  gladLoaderLoadGL();
  glViewport(0, 0, WinWidth, WinHeight);

  cubes = new Cubes;

  // Clear window and swap buffer
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glfwSwapBuffers(window);

  // Setup rotation
  prevTime = glfwGetTime();

  // Enable Depth Testing
  glEnable(GL_DEPTH_TEST);

  glfwSetWindowUserPointer(window, this);
}

Voxeloop::~Voxeloop() {
  // Destrroy and terminate
  delete cubes;
  delete audio;

  // Window
  glfwDestroyWindow(window);
  glfwTerminate();
}

void Voxeloop::run() {
  while (!glfwWindowShouldClose(window)) {
    loop();
  }
}

void Voxeloop::loop() {
  glfwPollEvents();
  glfwSetKeyCallback(window, key_callback);

  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  cubes->activateShader();

  // Rotate the object
  double crntTime = glfwGetTime();

  if (crntTime - prevTime >= 1 / 60) {
    mvmt -= 0.1f;
    cubes->rotate(1.5f);
    cubes->move(0.1f);
    prevTime = crntTime;
  }

  audio->traverseList(mvmt);

  cubes->scale(scale);
  cubes->draw();
  glfwSwapBuffers(window);
}

void Voxeloop::key_callback(GLFWwindow *window, int key, int scancode,
                            int action, int mods) {
  Voxeloop *vwin = static_cast<Voxeloop *>(glfwGetWindowUserPointer(window));
  Cubes *cubes = vwin->cubes;
  Audio *audio = vwin->audio;
  float *mvmt = &vwin->mvmt;
  float *scale = &vwin->scale;

  if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
    audio->play(' ');
    while (*mvmt <= 0.0f) {
      glfwPollEvents();
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      cubes->activateShader();
      cubes->move(-0.5f);
      cubes->scale(*scale);
      cubes->draw();

      glfwSwapBuffers(window);

      *mvmt += 0.5f;
    }
    audio->updateList();
  } else {
    if (action == GLFW_PRESS) {
      if (key == GLFW_KEY_A) {
        cubes->addCube();
        audio->addAudio('a', *mvmt);
      }

      if (key == GLFW_KEY_S) {
        cubes->addCube();
        audio->addAudio('s', *mvmt);
      }

      if (key == GLFW_KEY_D) {
        cubes->addCube();
        audio->addAudio('d', *mvmt);
      }

      if (key == GLFW_KEY_F) {
        cubes->addCube();
        audio->addAudio('f', *mvmt);
      }

      if (key == GLFW_KEY_J) {
        cubes->addCube();
        audio->addAudio('j', *mvmt);
      }

      if (key == GLFW_KEY_K) {
        cubes->addCube();
        audio->addAudio('k', *mvmt);
      }

      if (key == GLFW_KEY_L) {
        cubes->addCube();
        audio->addAudio('l', *mvmt);
      }

      if (key == GLFW_KEY_SEMICOLON) {
        cubes->addCube();
        audio->addAudio(';', *mvmt);
      }
    }

    if (key == GLFW_KEY_UP && action == GLFW_PRESS) {
      *scale += 0.1f;
    }

    if (key == GLFW_KEY_DOWN && action == GLFW_PRESS) {
      *scale -= 0.1f;
    }
  }
}
