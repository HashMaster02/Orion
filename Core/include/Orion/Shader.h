#pragma once

struct myVec4 {
  float v1;
  float v2;
  float v3;
  float v4;
};

unsigned int build_shader_program(const char *vertexSourcePath,
                                  const char *fragmentSourcePath);

void setUniformVec4f(unsigned int shader, const char *uniform, myVec4 values);
