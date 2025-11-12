#include <glad/glad.h>
#include <iostream>
#include "Orion/Input.h"
#include "Orion/Shader.h"
#include "Orion/Texture.h"
#include "Orion/Window.h"
#include "Utils/stb_image.h"

unsigned int create_triangle_object(float vertices[],
                                    size_t vertex_array_size) {
  unsigned int VAO, VBO;
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);

  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, vertex_array_size, vertices, GL_STATIC_DRAW);

  // Position Attribute
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  // Color Attribute
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
                        (void *)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  return VAO;
}

unsigned int create_index_buffer_object(float vertices[],
                                        size_t vertex_array_size,
                                        unsigned int indices[],
                                        size_t index_array_size) {
  unsigned int VAO, VBO, EBO;
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);

  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, vertex_array_size, vertices, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_array_size, indices,
               GL_STATIC_DRAW);

  // Position Attribute
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  // Color Attribute
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
                        (void *)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  // Texture Coordinates Attribute
  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
                        (void *)(6 * sizeof(float)));
  glEnableVertexAttribArray(2);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  return VAO;
}


int main() {
  // Create window
  OrionWindow *orion_window = (OrionWindow*)malloc(sizeof(OrionWindow));
  orion_window->width= 1280;
  orion_window->height = 720;
  orion_window->title = "Orion";
  orion_window->GLFWframebuffersizefun= framebuffer_size_callback;
  create_window(orion_window);

  if(!orion_window->window) {
    printf("Failed to create window");
    return -1;
  }

  float vertices[] = {
      0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // top right
      0.5f,  -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // bottom right
      -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
      -0.5f, 0.5f,  0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f  // top left
  };
  unsigned int indices[] = {0, 1, 3, 1, 2, 3};

  unsigned int shaderProgram = build_shader_program("./App/shaders/vertex.glsl", "./App/shaders/fragment_vertcol.glsl");
  if (shaderProgram == 0) {
    printf("ERROR: Couldn't build shader.");
    return -1;
  }
  unsigned int texture = generate_texture("./App/images/wall.jpg");
  unsigned int VAO = create_index_buffer_object(vertices, sizeof(vertices),
                                                indices, sizeof(indices));

  while (!close_window(orion_window)) {
    processInput(orion_window->window);

    // render
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shaderProgram);
    glBindTexture(GL_TEXTURE_2D, texture);

    // draw object
    glBindVertexArray(VAO);
    // glDrawArrays(GL_TRIANGLES, 0, 3);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glfwSwapBuffers(orion_window->window);
    glfwPollEvents();
  }

  glDeleteProgram(shaderProgram);
  destroy_window(orion_window);

  return 0;
}