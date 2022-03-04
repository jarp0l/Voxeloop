#include "../include/Window.hpp"
#include "GLFW/glfw3.h"

int Window::m_height = 0;
int Window::m_width = 0;
GLFWwindow *Window::m_window = nullptr;

// HANDLE WINDOW RESIZE
void window_resize(GLFWwindow *window, int width, int height);

void Window::create(std::string title, int width, int height) {
  m_title = title;
  m_width = width;
  m_height = height;

  ///////////////////// GLFW /////////////////////////
  // Initialize glfw
  if (!glfwInit()) {
    std::cerr << "[ERROR] Couldn't initialize GLFW" << std::endl;
    glfwTerminate();
  }
  std::cout << "[INFO] GLFW initialized" << std::endl;

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, m_glMajor);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, m_glMinor);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_SAMPLES, 4);

#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  // Get Monitor Properties
  GLFWmonitor *glfwMonitor = glfwGetPrimaryMonitor();
  const GLFWvidmode *glfwVidMode = glfwGetVideoMode(glfwMonitor);

  // Create GLFW Window
  m_window =
      glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);

  // Set Window Position
  glfwSetWindowPos(m_window, (glfwVidMode->width - m_width) / 2,
                   (glfwVidMode->height - m_height) / 2);

  // Check to make sure GLFW Window was created and fail if not
  if (!m_window) {
    std::cerr << "[ERROR] Couldn't create a GLFW Window" << std::endl;
    glfwTerminate();
    // return EXIT_FAILURE;
  }
  std::cout << "[INFO] GLFW Window created" << std::endl;

  // Set OpenGL current context to current window
  glfwMakeContextCurrent(m_window);

  // Set Callbacks
  glfwSetWindowSizeCallback(m_window, window_resize);
  glfwSetWindowUserPointer(m_window, this);

  glfwSwapInterval(1); // vsync

  /////////////////// GLAD /////////////////////
  // load all OpenGL function pointers with glad
  if (!gladLoaderLoadGL()) {
    std::cerr << "[ERROR] Couldn't initialize GLAD" << std::endl;
    // return EXIT_FAILURE;
  }
  std::cout << "[INFO] GLAD initialized" << std::endl;

  this->update();

  // Enable depth test
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_ALWAYS);
}

// CHECK TO SEE IF WINDOW CLOSE IS REAQUESTED
bool Window::isCloseRequested() { return glfwWindowShouldClose(m_window); }

// CLOSE WINDOW
void Window::close() { glfwSetWindowShouldClose(m_window, GLFW_TRUE); }

// UPDATE WINDOW
void Window::update() { glfwPollEvents(); }

// SWAP BUFFERS
void Window::render() { glfwSwapBuffers(m_window); }

// CLEAR SCREEN
void Window::clear() {
  glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::cleanup() {
  // GLFW Window cleanup
  glfwDestroyWindow(m_window);
  glfwTerminate();
}

// RETURN WINDOW WIDTH
int Window::getWidth() { return m_width; }

// RETURN WINDOW HEIGHT
int Window::getHeight() { return m_height; }

// RETURN GLFW WINDOW
GLFWwindow *Window::getWindow() { return m_window; }

// HANDLE WINDOW RESIZE
void window_resize(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}
