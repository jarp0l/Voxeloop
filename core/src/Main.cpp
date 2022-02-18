#include "Main.hpp"

const uint32_t GLMajor = 4;
const uint32_t GLMinor = 5;

const uint32_t WinWidth = 800;
const uint32_t WinHeight = 800;

// Vertices of coordinates
GLfloat vertices[] = {
    //   POSITIONS     /  COLORS             / TEXTURE COORDS
    -0.125f, 0.125f,  0.125f,  0.0f,
    0.0f,    0.0f,    0.0f,    0.0f, // Upper left corner
    0.125f,  0.125f,  0.125f,  0.0f,
    0.0f,    0.0f,    5.0f,    0.0f, // Upper right corner
    0.125f,  -0.125f, 0.125f,  0.0f,
    0.0f,    0.0f,    5.0f,    5.0f, // Lower right corner
    -0.125f, -0.125f, 0.125f,  0.0f,
    0.0f,    0.0f,    0.0f,    5.0f, // Lower left corner

    -0.125f, 0.125f,  -0.125f, 0.0f,
    0.0f,    0.0f,    5.0f,    5.0f, // Upper left corner
    0.125f,  0.125f,  -0.125f, 0.0f,
    0.0f,    0.0f,    0.0f,    5.0f, // Upper right corner
    0.125f,  -0.125f, -0.125f, 0.0f,
    0.0f,    0.0f,    0.0f,    0.0f, // Lower right corner
    -0.125f, -0.125f, -0.125f, 0.0f,
    0.0f,    0.0f,    5.0f,    0.0f // Lower left corner
};

// Indices of vertices
GLuint indices[] = {
    // face 1
    0, 1, 2, 2, 3, 0,
    // face 2
    4, 5, 6, 6, 7, 4,
    // face 3
    0, 4, 7, 7, 3, 0,
    // face 4
    1, 5, 6, 6, 2, 1,
    // face 5
    0, 4, 5, 5, 1, 0,
    // face 6
    3, 7, 6, 6, 2, 3};

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
<<<<<<< HEAD
  glViewport(0, 0, WinWidth, WinHeight);
=======
  glViewport(0, 0, 800, 800);

  Shader shader("../core/src/shaders/default.vert",
                "../core/src/shaders/default.frag");

  // Vertices of triangle
  GLfloat vertices[] = {
      //   POSITIONS          //   COLORS                          // TEXTURE
      //   COORDS
      -0.5f, 0.5f,  0.0f, 0.2f, 0.7f, 0.2f, 0.0f, 0.0f, // Upper left corner
      0.5f,  0.5f,  0.0f, 0.4f, 0.1f, 0.6f, 1.0f, 0.0f, // Upper right corner
      0.5f,  -0.5f, 0.0f, 0.2f, 0.4f, 0.5f, 1.0f, 1.0f, // Lower right corner
      -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f  // Lower left corner
  };
>>>>>>> 1ccb1ffc86654a6e73e54f74b3afbacb0a7b9415

  Shader shader("../core/shaders/default.vert", "../core/shaders/default.frag");

  // Define Vertex Array Object (VAO), Vertex Buffer Object (VBO) and Element
  // Buffer Object(EBO) ==> NOTE: Generate VAO before VBO
  VAO vao;
  vao.bind();
  VBO vbo(vertices, sizeof(vertices));
  EBO ebo(indices, sizeof(indices));

  vao.linkAttrib(vbo, 0, 3, GL_FLOAT, 8 * sizeof(float), (void *)0);
  vao.linkAttrib(vbo, 1, 3, GL_FLOAT, 8 * sizeof(float),
                 (void *)(3 * sizeof(float)));
  vao.linkAttrib(vbo, 2, 2, GL_FLOAT, 8 * sizeof(float),
                 (void *)(6 * sizeof(float)));

  vao.unbind();
  vbo.unbind();
  ebo.unbind();

  // Clear window and swap buffer
  glClearColor(0.1f, 0.3f, 0.2f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glfwSwapBuffers(window);

  // ID for "scale" uniform i.e. scale of the shape
  GLuint uniID = glGetUniformLocation(shader.ID, "scale");

  // Setup Texture
  Texture texture("../core/textures/great_img.png", GL_TEXTURE_2D, GL_TEXTURE0,
                  GL_RGB, GL_UNSIGNED_BYTE);

  // Setup Uniform for texture image
  texture.texUint(&shader, "tex0", 0);

  // Setup rotation
  float rotation = 0.0f;
  double prevTime = glfwGetTime();

  float zmove = 0.0f;

  // Enable Depth Testing
  glEnable(GL_DEPTH_TEST);

  // Main Event Loop
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();

    // Render
    glClearColor(0.1f, 0.3f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    shader.activate();

    // Rotate the object
    double crntTime = glfwGetTime();
    if (crntTime - prevTime >= 1 / 60) {
      rotation += 0.5f;
      zmove -= 0.1f;
      prevTime = crntTime;
    }

    // Model Matrix
    glm::mat4 model = glm::mat4(1.0f);

    // View Matrix
    glm::mat4 view = glm::mat4(1.0f);

    // Projection Matrix
    glm::mat4 proj = glm::mat4(1.0f);

    model =
        glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 1.0f, 0.0f));

    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -2.0f + zmove));

    proj = glm::perspective(glm::radians(45.0f), (float)(WinWidth / WinHeight),
                            0.1f, 25.0f);

    // Uniform for model matrix
    int modelLoc = glGetUniformLocation(shader.ID, "model");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

    // Uniform for view matrix
    int viewLoc = glGetUniformLocation(shader.ID, "view");
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

    // Uniform for projection matrix
    int projLoc = glGetUniformLocation(shader.ID, "proj");
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));

    glUniform1f(uniID, 1.5f);
    texture.bind();
    vao.bind();
    glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT,
                   0);
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
