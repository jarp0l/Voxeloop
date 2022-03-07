#include "Voxeloop.hpp"

void Voxeloop::init(GLFWwindow *window) {
  m_window = window;

  m_mvmt = 0.0f;
  m_scale = 1.0f;

  // Initialize Project
  m_audio = new Audio;
  m_cubes = new Cubes;

  // Setup rotation
  m_prevTime = glfwGetTime();

  glfwSetWindowUserPointer(window, this);

  std::cout << "[INFO] Voxeloop initialized\n";
}

void Voxeloop::cleanup() {
  delete m_cubes;
  delete m_audio;

  std::cout << "[INFO] Voxeloop cleaned\n";
}

void Voxeloop::run() { loop(); }

void Voxeloop::loop() {
  // m_gameData->window.clear();
  glClearColor(0.f, 0.f, 0.f, 1.f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glfwSetKeyCallback(m_window, key_callback);

  m_cubes->activateShader();

  // Rotate the object
  double crntTime = glfwGetTime();

  if (crntTime - m_prevTime >= 1 / 60) {
    m_mvmt -= 0.1f;
    m_cubes->rotate(1.5f);
    m_cubes->move(0.1f);
    m_prevTime = crntTime;
  }

  m_audio->traverseList(m_mvmt);

  m_cubes->scale(m_scale);
  m_cubes->draw();
}

void Voxeloop::key_callback(GLFWwindow *window, int key, int scancode,
                            int action, int mods) {
  Voxeloop *vwin = static_cast<Voxeloop *>(glfwGetWindowUserPointer(window));
  Cubes *cubes = vwin->m_cubes;
  Audio *audio = vwin->m_audio;
  float *mvmt = &vwin->m_mvmt;
  float *scale = &vwin->m_scale;

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
