#include "ImguiWrapper.hpp"
#include "GLFW/glfw3.h"
#include "imgui.h"
// #include "SharedData.hpp"

ImguiWrapper::ImguiWrapper() {}

ImguiWrapper::ImguiWrapper(GLFWwindow *window) : m_window{window} {
  this->init(window);
}

void ImguiWrapper::init(GLFWwindow *window) {
  // m_window = m_gameData->window.getWindow();

  // Setup Dear ImGui context
  /////////////////// Dear ImGui /////////////////////
  IMGUI_CHECKVERSION();
  // ImGui::CreateContext();
  // ImGuiIO &io = ImGui::GetIO();
  // (void)io;

  ImGui::CreateContext();
  m_window = window;
  m_style = &ImGui::GetStyle();
  m_io = &ImGui::GetIO();

  // Setup platform/renderer backends
  ImGui_ImplGlfw_InitForOpenGL(m_window,
                               true);            // platform: GLFW
  ImGui_ImplOpenGL3_Init(m_glslVersion.c_str()); // renderer: OpenGL

  // io.ConfigFlags |=
  //     ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
  // io.ConfigFlags |=
  //     ImGuiConfigFlags_NavEnableGamepad; // Enable Gamepad Controls
  // TO-DO: add a way to control things with mouse too

  // Setup Dear ImGui style to dark
  ImGui::StyleColorsDark();
}

void ImguiWrapper::getFrame() {
  // Start the Dear ImGui frame
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();
}

void ImguiWrapper::renderGUI() {
  ImGuiWindowFlags window_flags = 0;
  window_flags |= ImGuiWindowFlags_MenuBar;

  // glfwGetFramebufferSize(m_window, &displayWidth, &displayHeight);
  // glViewport(0, 0, displayWidth, displayHeight);
  // glClearColor(clearColor.x * clearColor.w, clearColor.y * clearColor.w,
  //              clearColor.z * clearColor.w, clearColor.w);
  // glClear(GL_COLOR_BUFFER_BIT);

  ImGui::Begin("Menu", &m_open, window_flags);
  ImGui::Text("Voxeloop");
  ImGui::End();

  // Rendering
  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void ImguiWrapper::cleanup() {
  // ImGui cleanup
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
}