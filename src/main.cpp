#include "main.hpp"

const uint32_t _glMajor = 4;
const uint32_t _glMinor = 5;

int main() {
  // Initialize Project
  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, _glMajor);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, _glMinor);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Setup Window
  GLFWwindow *window = glfwCreateWindow(800, 800, "Voxeloop", nullptr, nullptr);
  if (!window) {
    std::cout << "Couldn't open window" << std::endl;
    glfwTerminate();
    return EXIT_FAILURE;
  }
  glfwMakeContextCurrent(window);

  // Load GLAD and setup viewport
  gladLoaderLoadGL();
  glViewport(0, 0, 800, 800);

  Shader shader("../src/shaders/default.vert", "../src/shaders/default.frag");

  // Vertices of triangle
  GLfloat vertices[] = {
      -0.5f,     -0.5f * float(sqrt(3)) / 3,    0.0f, // Lower left corner
      0.5f,      -0.5f * float(sqrt(3)) / 3,    0.0f, // Lower right corner
      0.0f,      0.5f * float(sqrt(3)) * 2 / 3, 0.0f, // Upper corner
      -0.5f / 2, 0.5f * float(sqrt(3)) / 6,     0.0f, // Inner left
      0.5f / 2,  0.5f * float(sqrt(3)) / 6,     0.0f, // Inner right
      0.0f,      -0.5f * float(sqrt(3)) / 3,    0.0f  // Inner down
  };

  GLuint indices[] = {0, 3, 5, 3, 2, 4, 5, 4, 1};

  // Define Vertex Array Object (VAO), Vertex Buffer Object (VBO) and Element
  // Buffer Object(EBO) ==> NOTE: Generate VAO before VBO
  VAO vao;
  vao.bind();
  VBO vbo(vertices, sizeof(vertices));
  EBO ebo(indices, sizeof(indices));

  vao.linkVBO(vbo, 0);

  vao.unbind();
  vbo.unbind();
  ebo.unbind();

  // Clear window and swap buffer
  glClearColor(0.1f, 0.3f, 0.2f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glfwSwapBuffers(window);

  // Main Event Loop
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();

    // Render
    glClearColor(0.1f, 0.3f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    shader.activate();
    vao.bind();
    glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
    glfwSwapBuffers(window);
  }

  //// Destroy and terminate
  // VAO, VBO and Shader Program
  vao.remove();
  vbo.remove();
  ebo.remove();
  shader.remove();

  // Window
  glfwDestroyWindow(window);
  glfwTerminate();
  return EXIT_SUCCESS;
}
