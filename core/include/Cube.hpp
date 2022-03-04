#ifndef CORE_INCLUDE_CUBE_HPP
#define CORE_INCLUDE_CUBE_HPP

// clang-format off
#include <glad/gl.h>
#include <GLFW/glfw3.h>
// clang-format on
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#include "Shader.hpp"
#include "Texture.hpp"
#include "ebo.hpp"

#include "vao.hpp"
#include "vbo.hpp"

const uint32_t WinWidth = 800;
const uint32_t WinHeight = 800;

const uint8_t verticesSize = 64;
const uint8_t indicesSize = 36;

class Cube {
public:
  Cube();
  ~Cube();

  void setScaleUniform();
  void setTexUinform();
  void setMatUniform();

  void scale(float s);
  void rotate(float r);

  void move(float z);

  void activateShader();
  void draw();


private:
  Shader shader;
  GLfloat _vertices [verticesSize];
  GLuint _indices [indicesSize];

  Texture texture;

  VAO vao;
  VBO vbo;
  EBO ebo;

  // Model Matrix
  glm::mat4 model;

  // View Matrix
  glm::mat4 view;

  // Projection Matrix
  glm::mat4 proj;

  GLuint scaleUniID;

  float rotation = 0.0f;
  float zmove = 0.0f;

  GLfloat xpos, ypos;

  GLfloat random();
};

#endif // CORE_INCLUDE_CUBE_HPP
