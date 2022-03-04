#include "Main.hpp"

const uint32_t GLMajor = 4;
const uint32_t GLMinor = 5;


Cubes* cubes;
Audio* audio;


float mvmt = 0.0f;
float scale = 1.0f;

int main() {
  // Initialize Project
  audio = new Audio;
  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GLMajor);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GLMinor);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Setup Window

  GLFWwindow *window =
      glfwCreateWindow(WinWidth, WinHeight, "Voxeloop", nullptr, nullptr);

  if (!window) {
    std::cerr << "Couldn't open window" << std::endl;
    glfwTerminate();
    return EXIT_FAILURE;
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
  double prevTime = glfwGetTime();

  // Enable Depth Testing
  glEnable(GL_DEPTH_TEST);

  // Main Event Loop
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
    glfwSetKeyCallback(window, key_callback);

    // Render
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    cubes->activateShader();

    // Rotate the object
    double crntTime = glfwGetTime();

    if (crntTime - prevTime >= 1/60) {
      mvmt -= 0.1f;
      cubes->rotate(1.5f);
      cubes->move(0.1f);
      prevTime = crntTime;
    }

    cubes->scale(scale);
    cubes->draw();

    glfwSwapBuffers(window);
  }

  //// Destroy and terminate
  delete cubes;

  // Window
  glfwDestroyWindow(window);
  glfwTerminate();
  return EXIT_SUCCESS;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {

  if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
    audio->play(' ');
    while (mvmt <= 0.0f) {
      glfwPollEvents();
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      cubes->activateShader();
      cubes->move(-0.5f);
      cubes->scale(scale);
      cubes->draw();

      glfwSwapBuffers(window);

      mvmt += 0.5f;
    }
  } else {
    if (action == GLFW_PRESS) {
      if (key == GLFW_KEY_A) {
        cubes->addCube();
        audio->play('a');
      }

      if (key == GLFW_KEY_S) {
        cubes->addCube();
        audio->play('s');
      }

      if (key == GLFW_KEY_D) {
        cubes->addCube();
        audio->play('d');
      }

      if (key == GLFW_KEY_F) {
        cubes->addCube();
        audio->play('f');
      }

      if (key == GLFW_KEY_J) {
        cubes->addCube();
        audio->play('j');
      }

      if (key == GLFW_KEY_K) {
        cubes->addCube();
        audio->play('k');
      }

      if (key == GLFW_KEY_L) {
        cubes->addCube();
        audio->play('l');
      }

      if (key == GLFW_KEY_SEMICOLON) {
        cubes->addCube();
        audio->play(';');
      }
    }

    if (key == GLFW_KEY_UP && action == GLFW_PRESS) {
      scale += 0.1f;
    }

    if (key == GLFW_KEY_DOWN && action == GLFW_PRESS) {
      scale -= 0.1f;
    }
  }
}

