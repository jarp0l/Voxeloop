#ifndef CORE_INCLUDE_MAIN_HPP
#define CORE_INCLUDE_MAIN_HPP

// clang-format off
#include <glad/gl.h>
#include <GLFW/glfw3.h>
// clang-format on
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

#include "Cube.hpp"
#include "Cubes.hpp"
#include "LinkedList.hpp"

void key_callback(GLFWwindow *window, int key, int scancode, int action,
                  int mods);

#endif // CORE_INCLUDE_MAIN_HPP
