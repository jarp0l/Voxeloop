#include "../include/WindowManager.hpp"
#include "GLFW/glfw3.h"

int WindowManager::m_height = 0;
int WindowManager::m_width = 0;
GLFWwindow *WindowManager::m_window = nullptr;

// HANDLE WINDOW RESIZE
void window_resize(GLFWwindow *window, int width, int height);

void WindowManager::create(const char *title, int width, int height) {
  m_width = width;
  m_height = height;

  ///////////////////// GLFW /////////////////////////
  // Initialize GLFW
  if (!glfwInit()) {
    std::cerr << "[ERROR] Couldn't initialize GLFW" << std::endl;
    glfwTerminate();
  }
  std::cout << "[INFO] GLFW initialized" << std::endl;

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_SAMPLES, 4);

#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  // Get Monitor Properties
  GLFWmonitor *glfwMonitor = glfwGetPrimaryMonitor();
  const GLFWvidmode *glfwVidMode = glfwGetVideoMode(glfwMonitor);

  // Create GLFW Window
  m_window = glfwCreateWindow(m_width, m_height, title, nullptr, nullptr);

  // Set Window Position
  glfwSetWindowPos(m_window, (glfwVidMode->width - m_width) / 2,
                   (glfwVidMode->height - m_height) / 2);

  // Check to make sure GLFW Window was created and fail if not
  if (!m_window) {
    std::cerr << "[ERROR] Couldn't create a GLFW Window" << std::endl;
    glfwTerminate();
  }
  std::cout << "[INFO] GLFW Window created" << std::endl;

  // Set OpenGL current context to current window
  glfwMakeContextCurrent(m_window);

  // Set Callbacks
  glfwSetWindowSizeCallback(m_window, window_resize);
  glfwSetWindowUserPointer(m_window, this);

  glfwSwapInterval(1); // vsync

  /////////////////// GLAD /////////////////////
  // Load all OpenGL function pointers with glad
  if (!gladLoaderLoadGL()) {
    std::cerr << "[ERROR] Couldn't initialize GLAD" << std::endl;
  }
  std::cout << "[INFO] GLAD initialized" << std::endl;

  this->update();

  // Enable depth test
  glEnable(GL_DEPTH_TEST);
}

// Check to see if window close is reaquested
bool WindowManager::isCloseRequested() {
  return glfwWindowShouldClose(m_window);
}

// Close window
void WindowManager::close() { glfwSetWindowShouldClose(m_window, GLFW_TRUE); }

// Update window
void WindowManager::update() { glfwPollEvents(); }

// Swap buffers
void WindowManager::render() { glfwSwapBuffers(m_window); }

// Clear screen
void WindowManager::clear() {
  // RGB = 37, 30, 62
  uint8_t red = 37;
  uint8_t green = 30;
  uint8_t blue = 62;

  glClearColor((float)red / 255, (float)green / 255, (float)blue / 255, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void WindowManager::cleanup() {
  // GLFW Window cleanup
  glfwDestroyWindow(m_window);
  glfwTerminate();
}

// Return window width
int WindowManager::getWidth() { return m_width; }

// Return window height
int WindowManager::getHeight() { return m_height; }

// Return glfw window
GLFWwindow *WindowManager::getWindow() { return m_window; }

// Handle window resize
void window_resize(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}
