#include "Main.hpp"

const uint32_t GLMajor = 4;
const uint32_t GLMinor = 5;

int main() {
  // Initialize Project
  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GLMajor);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GLMinor);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Setup Window
  GLFWwindow *window = glfwCreateWindow(WinWidth, WinHeight, "Voxeloop", nullptr, nullptr);
  if (!window) {
    std::cerr << "Couldn't open window" << std::endl;
    glfwTerminate();
    return EXIT_FAILURE;
  }
  glfwMakeContextCurrent(window);

  // Load GLAD and setup viewport
  gladLoaderLoadGL();
  glViewport(0, 0, WinWidth, WinHeight);


  Cube* cube = new Cube;

  // Clear window and swap buffer
  glClearColor(0.1f, 0.3f, 0.2f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glfwSwapBuffers(window);


  // ID for "scale" uniform i.e. scale of the shape
  cube->setScaleUniform();



  // Setup Uniform for texture image
  cube->setTexUinform();

  // Setup rotation
  double prevTime = glfwGetTime();

  // Enable Depth Testing
  glEnable(GL_DEPTH_TEST);

  // Main Event Loop
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();

    // Render
    glClearColor(0.1f, 0.3f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    cube->activateShader();

    // Rotate the object
    double crntTime = glfwGetTime();


    if (crntTime - prevTime >= 1/60) {
      cube->rotate(1.5f);
      cube->move(0.1f);
      prevTime = crntTime;
    }

    cube->scale(1.0f);
    cube->draw();
    glfwSwapBuffers(window);
  }

  //// Destroy and terminate
  delete cube;
  // Window
  glfwDestroyWindow(window);
  glfwTerminate();
  return EXIT_SUCCESS;
}
