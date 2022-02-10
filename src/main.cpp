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

  Shader shader("shaders/default.vert", "shaders/default.frag");

  // Vertices of triangle
  GLfloat vertices[] = {
       //   POSITIONS          //   COLORS                          // TEXTURE COORDS
      -0.5f, 0.5f, 0.0f, 0.2f, 0.7f, 0.2f, 0.0f, 0.0f, // Upper left corner
      0.5f, 0.5f, 0.0f, 0.4f, 0.1f, 0.6f, 1.0f, 0.0f,// Upper right corner
      0.5f, -0.5f, 0.0f, 0.2f, 0.4f, 0.5f, 1.0f, 1.0f,// Lower right corner
      -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f // Lower left corner

  };

  GLuint indices[] = {
      0, 1, 2,
      2, 3, 0
  };

  // Define Vertex Array Object (VAO), Vertex Buffer Object (VBO) and Element
  // Buffer Object(EBO) ==> NOTE: Generate VAO before VBO
  VAO vao;
  vao.bind();
  VBO vbo(vertices, sizeof(vertices));
  EBO ebo(indices, sizeof(indices));

  vao.linkAttrib(vbo, 0, 3, GL_FLOAT, 8*sizeof(float), (void*) 0);
  vao.linkAttrib(vbo, 1, 3, GL_FLOAT, 8*sizeof(float), (void*) (3* sizeof(float)));
  vao.linkAttrib(vbo, 2, 2, GL_FLOAT, 8*sizeof(float), (void*) (6* sizeof(float)));
  vao.unbind();
  vbo.unbind();
  ebo.unbind();


  // Clear window and swap buffer
  glClearColor(0.1f, 0.3f, 0.2f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glfwSwapBuffers(window);

  // ID for "scale" uniform i.e. scale of the shape
  GLuint  uniID = glGetUniformLocation(shader.ID, "scale");

  // Setup Texture
  Texture texture("textures/great_img.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);

  // Setup Uniform for texture image
  texture.texUint(&shader, "tex0", 0);

  // Main Event Loop
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();

    // Render
    glClearColor(0.1f, 0.3f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    shader.activate();
    glUniform1f(uniID, 0.0f);
    texture.bind();
    vao.bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glfwSwapBuffers(window);
  }

  //// Destroy and terminate
  // Shader and Texture
  vao.remove();
  vbo.remove();
  ebo.remove();

  texture.remove();

  shader.remove();

  // Window
  glfwDestroyWindow(window);
  glfwTerminate();
  return EXIT_SUCCESS;
}
