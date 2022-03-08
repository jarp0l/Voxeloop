#ifndef VOXELOOP_LIGHTSOURCE_HPP
#define VOXELOOP_LIGHTSOURCE_HPP

// clang-format off
#include <glad/gl.h>
#include <GLFW/glfw3.h>
// clang-format on
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#include "ebo.hpp"
#include "Shader.hpp"
#include "VAO.hpp"
#include "VBO.hpp"

const uint32_t ls_verticesSize = 5;
const uint32_t ls_indicesSize = 5;

class LightSource {
public:
  LightSource();
  ~LightSource();
  void setMatUniform();

  void activateShader();
  void draw();

private:
  Shader shader;
  GLfloat _vertices [ls_verticesSize];
  GLuint _indices [ls_indicesSize];

  VAO vao;
  VBO vbo;
  EBO ebo;

  // Model Matrix
  glm::mat4 model;

  // View Matrix
  glm::mat4 view;

  // Projection Matrix
  glm::mat4 proj;
};

#endif // VOXELOOP_LIGHTSOURCE_HPP
