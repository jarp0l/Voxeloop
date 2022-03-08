#include "GUIManager.hpp"
#include "imgui.h"

GUIManager::GUIManager() {}

GUIManager::GUIManager(GLFWwindow *window) { this->init(window); }

void GUIManager::init(GLFWwindow *window) {
  // m_window = m_gameData->window.getWindow();

  // Setup Dear ImGui context
  /////////////////// Dear ImGui /////////////////////
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();

  // Setup platform/renderer backends
  ImGui_ImplGlfw_InitForOpenGL(window,
                               true);     // platform: GLFW
  ImGui_ImplOpenGL3_Init("#version 450"); // renderer: OpenGL

  ImGuiStyle &style = ImGui::GetStyle();
  ImGuiIO &io = ImGui::GetIO();
  (void)io;

  const char *fontPath = "../core/assets/fonts/ineptic/Ineptic.ttf";
  io.Fonts->AddFontFromFileTTF(fontPath, 36.0f);

  // merge in icons from Font Awesome
  static const ImWchar icons_ranges[] = {ICON_MIN_FA, ICON_MAX_FA, 0};
  ImFontConfig icons_config;
  icons_config.MergeMode = true;
  icons_config.PixelSnapH = true;
  io.Fonts->AddFontFromFileTTF(FONT_ICON_FILE_NAME, 36.0f, &icons_config,
                               icons_ranges);

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

void GUIManager::begin() { this->getFrame(); }

void GUIManager::end() { this->render(); }

bool GUIManager::renderBackButton() {
  bool nextState = false;

  ImGuiWindowFlags windowFlags = 0;
  windowFlags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBackground |
                 ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize;

  ImGui::Begin("Back", &m_open, windowFlags);
  ImGui::SetWindowPos(ImVec2(0, 0));
  ImGui::SetWindowSize(ImVec2(500, 500));

  // change to menu state
  if (ImGui::Button("Back", ImVec2(100, 50)))
    nextState = true;
  ImGui::End();

  this->render();

  return nextState;
}

uint8_t GUIManager::renderMenu(WindowManager *window) {
  uint8_t nextState = 0;

  ImGuiWindowFlags windowFlags = 0;
  windowFlags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBackground |
                 ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings |
                 ImGuiWindowFlags_NoResize;

  int ImGuiWinX = window->getWidth() / 2;
  int ImGuiWinY = window->getHeight() / 4;

  ImGui::Begin("Menu", &m_open, windowFlags);
  ImGui::SetWindowPos(ImVec2(ImGuiWinX + 175, ImGuiWinY));
  ImGui::SetWindowSize(ImVec2(200, 400));
  {
    if (ImGui::Button("Start", ImVec2(150, 75)))
      nextState = 1;
    if (ImGui::IsItemHovered()) {
      // do something if the item is hovered
    }
    ImGui::Dummy(ImVec2(0, 20));
  }
  {
    if (ImGui::Button("Settings", ImVec2(150, 75)))
      nextState = 2;
    if (ImGui::IsItemHovered()) {
      // do something if the item is hovered
    }
    ImGui::Dummy(ImVec2(0, 20));
  }
  {
    if (ImGui::Button("About", ImVec2(150, 75)))
      nextState = 3;
    if (ImGui::IsItemHovered()) {
      // do something if the item is hovered
    }
    ImGui::Dummy(ImVec2(0, 20));
  }
  {
    if (ImGui::Button("Exit", ImVec2(150, 75))) {
      window->close();
      nextState = 15;
    }
    if (ImGui::IsItemHovered()) {
      // do something if the item is hovered
    }
  }

  ImGui::End();

  return nextState;
}

uint8_t GUIManager::renderSettings(WindowManager *window) {
  uint8_t nextState = 0;
  ImGuiWindowFlags windowFlags = 0;
  // windowFlags |= ImGuiWindowFlags_NoTitleBar;

  int ImGuiWinX = window->getWidth() / 6;
  int ImGuiWinY = window->getHeight() / 6;

  ImGui::Begin("Settings", &m_open, windowFlags);
  ImGui::SetWindowPos(ImVec2(ImGuiWinX, ImGuiWinY));
  ImGui::SetWindowSize(ImVec2(1100, 550));

  ImGui::Text("Test");

  ImGui::End();

  if (this->renderBackButton())
    nextState = 1;

  return nextState;
}

uint8_t GUIManager::renderAbout(WindowManager *window) {
  uint8_t nextState = 0;
  ImGuiWindowFlags windowFlags = 0;
  // windowFlags |= ImGuiWindowFlags_NoTitleBar;

  int ImGuiWinX = window->getWidth() / 6;
  int ImGuiWinY = window->getHeight() / 6;

  ImGui::Begin("About", &m_open, windowFlags);
  ImGui::SetWindowPos(ImVec2(ImGuiWinX, ImGuiWinY));
  ImGui::SetWindowSize(ImVec2(1100, 550));

  ImGui::Text("Voxeloop: Musical Loop Generation in Voxel World");
  ImGui::Dummy(ImVec2(0, 50));
  ImGui::Text(
      "Voxeloop is a musical loop generating and playing system.\nUse "
      "your keyboard (like a \"launchpad\") to generate musical loops \n"
      "along with voxels. Press a key to listen to these again. Enjoy!");
  ImGui::Dummy(ImVec2(0, 200));
  ImGui::Text("Created with " ICON_FA_HEART " by Prajwol & Rujal");

  ImGui::End();

  if (this->renderBackButton())
    nextState = 1;

  return nextState;
}

void GUIManager::cleanup() {
  // ImGui cleanup
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
}