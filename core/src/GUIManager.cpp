#include "GUIManager.hpp"
#include "imgui.h"

GUIManager::GUIManager() {}

// GUIManager::GUIManager(GLFWwindow *window) : m_window{window} {
GUIManager::GUIManager(GLFWwindow *window) { this->init(window); }

void GUIManager::init(GLFWwindow *window) {
  // m_window = m_gameData->window.getWindow();

  // Setup Dear ImGui context
  /////////////////// Dear ImGui /////////////////////
  IMGUI_CHECKVERSION();
  // ImGui::CreateContext();
  // ImGuiIO &io = ImGui::GetIO();
  // (void)io;

  ImGui::CreateContext();

  // Setup platform/renderer backends
  ImGui_ImplGlfw_InitForOpenGL(window,
                               true);     // platform: GLFW
  ImGui_ImplOpenGL3_Init("#version 450"); // renderer: OpenGL
  // m_window = window;
  // m_style = &ImGui::GetStyle();
  // m_io = &ImGui::GetIO();
  ImGuiStyle &style = ImGui::GetStyle();
  ImGuiIO &io = ImGui::GetIO();
  (void)io;

  io.Fonts->AddFontDefault();

  // merge in icons from Font Awesome
  static const ImWchar icons_ranges[] = {ICON_MIN_FA, ICON_MAX_FA, 0};
  ImFontConfig icons_config;
  icons_config.MergeMode = true;
  icons_config.PixelSnapH = true;
  // io.Fonts->AddFontFromFileTTF(FONT_ICON_FILE_NAME, 16.0f, &icons_config,
  //                              icons_ranges);
  // use FONT_ICON_FILE_NAME_FAR if you want regular instead of solid

  // io.ConfigFlags |=
  //     ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
  // io.ConfigFlags |=
  //     ImGuiConfigFlags_NavEnableGamepad; // Enable Gamepad Controls

  // Setup Dear ImGui style to dark
  ImGui::StyleColorsDark();
}

void GUIManager::getFrame() {
  // Start the Dear ImGui frame
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();
}

void GUIManager::render() {
  // Rendering
  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

bool GUIManager::renderBackButton() {
  bool nextState = false;

  ImGuiWindowFlags windowFlags = 0;
  windowFlags = ImGuiWindowFlags_NoDecoration;
  windowFlags |= ImGuiWindowFlags_NoBackground;

  ImGui::Begin("Back", &m_open, windowFlags);
  // if (ImGui::Button("Back to menu"))
  // change to menu state
  if (ImGui::Button("Back to Menu"))
    nextState = true;
  ImGui::End();

  this->render();

  return nextState;
}

uint8_t GUIManager::renderMenu(WindowManager *window) {
  uint8_t nextState = 0;

  ImGuiWindowFlags windowFlags = 0;
  windowFlags |= ImGuiWindowFlags_NoTitleBar;
  // windowFlags |= ImGuiWindowFlags_NoBackground;

  ImGui::Begin("Menu", &m_open, windowFlags);

  if (ImGui::Button("Start"))
    nextState = 1;
  if (ImGui::Button("Settings"))
    nextState = 2;
  if (ImGui::Button("About"))
    nextState = 3;
  if (ImGui::Button("Exit")) {
    window->close();
    nextState = 15;
  }

  // in an imgui window somewhere...
  // ImGui::Text(ICON_FA_PAINT_BRUSH
  //             "  Paint"); // use string literal concatenation
  // outputs a paint brush icon and 'Paint' as a string.

  ImGui::End();

  this->render();

  return nextState;
}

void GUIManager::renderSettings() {
  ImGuiWindowFlags windowFlags = 0;
  windowFlags |= ImGuiWindowFlags_NoTitleBar;

  // ImGui::Begin("Settings", &m_open, windowFlags);
  // ImGui::Text("Test");
  // ImGui::End();

  this->render();
}

void GUIManager::cleanup() {
  // ImGui cleanup
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
}