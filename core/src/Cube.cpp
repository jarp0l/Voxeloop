#include "Cube.hpp"


Cube::Cube() :
  shader {"../core/shaders/default.vert", "../core/shaders/default.frag"},
  _vertices {
                   //   POSITIONS     /  COLORS             / TEXTURE COORDS
                   -0.125f,  0.125f,  0.125f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f, // Upper left corner
                   0.125f,  0.125f,  0.125f,  0.0f,  0.0f,  0.0f,  5.0f,  0.0f, // Upper right corner
                   0.125f, -0.125f,  0.125f,  0.0f,  0.0f,  0.0f,  5.0f,  5.0f, // Lower right corner
                   -0.125f, -0.125f,  0.125f,  0.0f,  0.0f,  0.0f,  0.0f,  5.0f,  // Lower left corner

                   -0.125f,  0.125f, -0.125f,  0.0f,  0.0f,  0.0f,  5.0f,  5.0f, // Upper left corner
                   0.125f,  0.125f, -0.125f,  0.0f,  0.0f,  0.0f,  0.0f,  5.0f, // Upper right corner
                   0.125f, -0.125f, -0.125f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f, // Lower right corner
                   -0.125f, -0.125f, -0.125f,  0.0f,  0.0f,  0.0f,  5.0f,  0.0f  // Lower left corner
               },
  _indices {
                   // face 1
                   0, 1, 2,
                   2, 3, 0,
                   // face 2
                   4, 5, 6,
                   6, 7, 4,
                   // face 3
                   0, 4, 7,
                   7, 3, 0,
                   // face 4
                   1, 5, 6,
                   6, 2, 1,
                   // face 5
                   0, 4, 5,
                   5, 1, 0,
                   // face 6
                   3, 7, 6,
                   6, 2, 3
            },
  texture {"../core/textures/great_img.png", GL_TEXTURE_2D, GL_TEXTURE0,
                                 GL_RGB, GL_UNSIGNED_BYTE}
{

  vao.bind();

  vbo.setup(_vertices, sizeof(_vertices));
  ebo.setup(_indices, sizeof(_indices));

  vao.linkAttrib(vbo, 0, 3, GL_FLOAT, 8 * sizeof(float), (void *)0);
  vao.linkAttrib(vbo, 1, 3, GL_FLOAT, 8 * sizeof(float),
                 (void *)(3 * sizeof(float)));
  vao.linkAttrib(vbo, 2, 2, GL_FLOAT, 8 * sizeof(float),
                 (void *)(6 * sizeof(float)));

  vao.unbind();
  vbo.unbind();
  ebo.unbind();

  xpos = random();
  ypos = random();
}

Cube::~Cube() {
  vao.remove();
  vbo.remove();
  ebo.remove();
  texture.remove();
  shader.remove();
}


void Cube::setScaleUniform() {scaleUniID =  glGetUniformLocation(shader.ID, "scale");}

void Cube::setTexUinform() {texture.texUint(&shader, "tex0", 0);}


void Cube::setMatUniform() {
  // Uniform for model matrix
  int modelLoc = glGetUniformLocation(shader.ID, "model");
  glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

  // Uniform for view matrix
  int viewLoc = glGetUniformLocation(shader.ID, "view");
  glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

  // Uniform for projection matrix
  int projLoc = glGetUniformLocation(shader.ID, "proj");
  glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));
}


void Cube::scale(float s) { glUniform1f(scaleUniID, s); }

void Cube::rotate(float r) { rotation += r; }

void Cube::activateShader() { shader.activate(); }


void Cube::draw() {
  // Model Matrix
  model = glm::mat4(1.0f);

  // View Matrix
  view = glm::mat4(1.0f);

  // Projection Matrix
  proj = glm::mat4(1.0f);



  model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 1.0f, 0.0f));

  view = glm::translate(view, glm::vec3(xpos, ypos, -2.0f + zmove));

  proj = glm::perspective(glm::radians(45.0f), (float)(WinWidth/WinHeight), 0.1f, 25.0f);


  setMatUniform();
  texture.bind();
  vao.bind();

  glDrawElements(GL_TRIANGLES, sizeof(_indices) / sizeof(int), GL_UNSIGNED_INT,
                 0);
}

void Cube::move(float z) { zmove -= z; }

GLfloat Cube::random() {
  GLfloat ran = float(rand() % 10) / 10.0f;
  if (rand() % 2 == 0) {
    return ran;
  } else {
    return -ran;
  }
}
