///
/// @file vao.cpp
/// @author Prajwol Pradhan & Rujal Acharya
/// @brief Vertex Array Object for
/// @version 0.1
/// @date 2022-02-16
///
#include "vao.hpp"

VAO::VAO() { glGenVertexArrays(1, &ID); }

void VAO::bind() { glBindVertexArray(ID); }

void VAO::unbind() { glBindVertexArray(0); }

void VAO::remove() { glDeleteVertexArrays(1, &ID); }

void VAO::linkAttrib(VBO &vbo, GLuint layout, GLuint numComponents, GLenum type,
                     GLsizeiptr stride, void *offset) {
  vbo.bind();
  glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
  glEnableVertexAttribArray(layout);
  vbo.unbind();
}
