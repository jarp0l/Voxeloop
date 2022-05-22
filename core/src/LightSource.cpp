#include "LightSource.hpp"

LightSource::LightSource() :
    shader{"../core/shaders/light.vert", "../core/shaders/light.frag"},
    _vertices{
            // clang-format off
                   //   POSITIONS                            /  COLORS                       / TEXTURE COORDS
                   // Face 1
                   -0.125f,   0.125f,  0.125f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f, // Upper left corner - f
                    0.125f,   0.125f, 0.125f,  0.0f,  0.0f,  0.0f,  1.0f,  0.0f, // Upper right corner - f
                   0.125f, -0.125f, 0.125f,  0.0f,  0.0f,  0.0f,  1.0f,  1.0f, // Lower right corner - f
                   -0.125f,-0.125f, 0.125f,  0.0f,  0.0f,  0.0f,  0.0f,  1.0f,  // Lower left corner - f

                   // Face 2
                   -0.125f,  0.125f, -0.125f,  0.0f,  0.0f,  0.0f,  1.0f,  0.0f, // Upper left corner - b
                   0.125f,  0.125f, -0.125f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f, // Upper right corner - b
                   0.125f, -0.125f, -0.125f,  0.0f,  0.0f,  0.0f,  0.0f,  1.0f, // Lower right corner - b
                   -0.125f, -0.125f, -0.125f,  0.0f,  0.0f,  0.0f,  1.0f,  1.0f,  // Lower left corner - b

                   // Face 3
                   -0.125f,   0.125f,  0.125f,  0.0f,  0.0f,  0.0f,  1.0f,  0.0f, // Upper left corner - f
                   -0.125f,-0.125f, 0.125f,  0.0f,  0.0f,  0.0f,  1.0f,  1.0f,  // Lower left corner - f
                   -0.125f, -0.125f, -0.125f,  0.0f,  0.0f,  0.0f,  0.0f,  1.0f,  // Lower left corner - b
                   -0.125f,  0.125f, -0.125f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f, // Upper left corner - b

                   // Face 4
                   0.125f,   0.125f, 0.125f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f, // Upper right corner - f
                   0.125f, -0.125f, 0.125f,  0.0f,  0.0f,  0.0f,  0.0f,  1.0f, // Lower right corner - f
                   0.125f, -0.125f, -0.125f,  0.0f,  0.0f,  0.0f,  1.0f,  1.0f, // Lower right corner - b
                   0.125f,  0.125f, -0.125f,  0.0f,  0.0f,  0.0f,  1.0f,  0.0f, // Upper right corner - b

                   // Face 5
                   -0.125f,   0.125f,  0.125f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f, // Upper left corner - f
                   0.125f,   0.125f, 0.125f,  0.0f,  0.0f,  0.0f,  1.0f,  0.0f, // Upper right corner - f
                   0.125f,  0.125f, -0.125f,  0.0f,  0.0f,  0.0f,  1.0f,  1.0f, // Upper right corner - b
                   -0.125f,  0.125f, -0.125f,  0.0f,  0.0f,  0.0f,  0.0f,  1.0f, // Upper left corner - b


                   // Face 6
                   0.125f, -0.125f, 0.125f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f, // Lower right corner - f
                   -0.125f,-0.125f, 0.125f,  0.0f,  0.0f,  0.0f,  1.0f,  0.0f,  // Lower left corner - f
                   -0.125f, -0.125f, -0.125f,  0.0f,  0.0f,  0.0f,  1.0f,  1.0f,  // Lower left corner - b
                   0.125f, -0.125f, -0.125f,  0.0f,  0.0f,  0.0f,  0.0f,  1.0f // Lower right corner - b
                             },
    _indices{
          // clang-format off
                   // face 1
                   0, 1, 2,
                   2, 3, 0,

                   // face 2
                   4, 5, 6,
                   6, 7, 4,
                   // face 3
//                   0, 4, 7,
//                   7, 3, 0,
//                   // face 4
//                   1, 5, 6,
//                   6, 2, 1,
//                   // face 5
//                   0, 4, 5,
//                   5, 1, 0,
//                   // face 6
//                   3, 7, 6,
//                   6, 2, 3
                   //face 3
                   8, 9, 10,
                   10, 11, 8,

                   //face 4
                   12, 13, 14,
                   14, 15, 12,

                   // face 5
                   16, 17, 18,
                   18, 19, 16,

                   // face 6
                   20, 21, 22,
                   22, 23, 20
          // clang-format on
      } {
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

}

LightSource::~LightSource() {
  vao.remove();
  vbo.remove();
  ebo.remove();
  shader.remove();
}

void LightSource::setMatUniform() {
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

void LightSource::activateShader() { shader.activate(); }

void LightSource::draw() {
  // Model Matrix
  model = glm::mat4(1.0f);

  // View Matrix
  view = glm::mat4(1.0f);

  // Projection Matrix
  proj = glm::mat4(1.0f);

  model =
      glm::rotate(model, glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

  view = glm::translate(view, glm::vec3(0.2f, 0.2f, 0.2f));

  proj = glm::perspective(glm::radians(45.0f), (float)(800 / 800),
                          0.1f, 25.0f);

  setMatUniform();
//   texture.bind();
  vao.bind();

  glDrawElements(GL_TRIANGLES, sizeof(_indices) / sizeof(int), GL_UNSIGNED_INT,
                 0);
}
