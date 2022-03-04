#include "Main.hpp"

const uint32_t GLMajor = 4;
const uint32_t GLMinor = 5;

Cubes* cubes;

float mvmt = 0.0f;
float scale = 1.0f;

int main() {
  // Initialize Project
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
//  delete cube;
  // Window
  glfwDestroyWindow(window);
  glfwTerminate();
  return EXIT_SUCCESS;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
  if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
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
  }

  if (key == GLFW_KEY_E && action == GLFW_PRESS) {
    cubes->addCube();
  }

  if (key == GLFW_KEY_UP && action == GLFW_PRESS) {
    scale += 0.1f;
  }

  if (key == GLFW_KEY_DOWN && action == GLFW_PRESS) {
    scale -= 0.1f;
  }
}


 