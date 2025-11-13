#pragma once
#include "glm/glm.hpp"

namespace Orion {
  unsigned int build_shader_program(const char *vertexSourcePath, const char *fragmentSourcePath);

  void setUniformVec4f(unsigned int shader, const char *uniform, glm::vec4 values);
  void setUniformMat4fv(unsigned int shader, const char *uniform, glm::mat4 &matrix);
}