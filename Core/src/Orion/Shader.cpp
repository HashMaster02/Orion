
#include "Orion/Shader.h"
#include "glad/glad.h"
#include "Utils/File.h"
#include <GLFW/glfw3.h>
#include <cstdio>
#include <iostream>
#include <stdio.h>

unsigned int build_vertex_shader(const char *vertexSourcePath) {
  const char *vertexShaderSource = readFileToString(vertexSourcePath);
  if (!vertexShaderSource) {
    printf("ERROR: Couldn't find Vertex Shader source\n");
    return 0;
  }

  unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);

  int success;
  char infoLog[512];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n");
    return 0;
  }

  return vertexShader;
}

unsigned int build_fragment_shader(const char *fragmentSourcePath) {

  const char *fragmentShaderSource = readFileToString(fragmentSourcePath);
  if (!fragmentShaderSource) {
    printf("ERROR: Couldn't find Fragment Shader source\n");
    return 0;
  }

  unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);

  int success;
  char infoLog[512];
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n");
    return 0;
  }

  return fragmentShader;
}

unsigned int build_shader_program(const char *vertexSourcePath,
                                  const char *fragmentSourcePath) {
  unsigned int vertexShader = build_vertex_shader(vertexSourcePath);
  unsigned int fragmentShader = build_fragment_shader(fragmentSourcePath);

  if (vertexShader == 0 || fragmentShader == 0) {
    return 0;
  }

  // link shaders
  unsigned int shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);

  // check for linking errors
  int success;
  char infoLog[512];
  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    printf("ERROR::SHADER::PROGRAM::LINKING_FAILED\n");
    return -1;
  }
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  return shaderProgram;
}

void setUniformVec4f(unsigned int shader, const char *uniform, myVec4 values) {

  int vertexColorLoc = glGetUniformLocation(shader, uniform);

  if (vertexColorLoc == -1) {
    std::printf("ERROR: UNIFORM NOT FOUND: %s", uniform);
    return;
  }

  glUniform4f(vertexColorLoc, values.v1, values.v2, values.v3, values.v4);
}
