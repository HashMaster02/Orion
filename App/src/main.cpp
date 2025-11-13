#include <glad/glad.h>
#include <iostream>
#include "Orion/Input.h"
#include "Orion/Shader.h"
#include "Orion/Texture.h"
#include "Orion/Window.h"
#include "Orion/Object.h"
#include "Orion/Renderer.h"
#include "Utils/stb_image.h"
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

int main() {
  // Create window
  Orion::Window *orion_window = (Orion::Window*)malloc(sizeof(Orion::Window));
  orion_window->width= 1280;
  orion_window->height = 720;
  orion_window->title = "Orion";
  orion_window->GLFWframebuffersizefun= Orion::framebuffer_size_callback;

  Orion::create_window(orion_window);
  if(!orion_window->window) {
    printf("Failed to create window");
    return -1;
  }

  // world space positions of our cubes
  glm::vec3 cubePositions[] = {
      glm::vec3( 0.0f,  0.0f,  0.0f),
      glm::vec3( 2.0f,  5.0f, -15.0f),
      glm::vec3(-1.5f, -2.2f, -2.5f),
      glm::vec3(-3.8f, -2.0f, -12.3f),
      glm::vec3( 2.4f, -0.4f, -3.5f),
      glm::vec3(-1.7f,  3.0f, -7.5f),
      glm::vec3( 1.3f, -2.0f, -2.5f),
      glm::vec3( 1.5f,  2.0f, -2.5f),
      glm::vec3( 1.5f,  0.2f, -1.5f),
      glm::vec3(-1.3f,  1.0f, -1.5f)
  };

  unsigned int shaderProgram = Orion::build_shader_program("./App/shaders/default_vertex.glsl", "./App/shaders/default_fragment.glsl");
  if (shaderProgram == 0) {
    printf("ERROR: Failed to build shader.");
    return -1;
  }
  Orion::use_shader(shaderProgram);

  unsigned int texture = Orion::generate_texture("./App/images/wall.jpg");
  if (texture == 0) {
    printf("ERROR: Failed to generate texture.");
    return -1;
  }
  Orion::use_texture2d(texture);

  unsigned int VAO_cube = Orion::create_object(Orion::default_cube, Orion::default_cube_size);

  glm::mat4 projection    = glm::mat4(1.0f);
  projection = glm::perspective(glm::radians(45.0f), (float)orion_window->width / (float)orion_window->height, 0.1f, 100.0f);
  Orion::setUniformMat4fv(shaderProgram, "projection", projection);

  while (!close_window(orion_window)) {
    Orion::processInput(orion_window->window);

    glm::vec4 clearCol(0.2f, 0.3f, 0.3f, 1.0f);
    glClearColor(clearCol.x, clearCol.y, clearCol.z, clearCol.w);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::mat4 view_mat = glm::mat4(1.0f);
    float radius = 10.0f;
    float camX = static_cast<float>(sin(glfwGetTime()) * radius);
    float camZ = static_cast<float>(cos(glfwGetTime()) * radius);
    view_mat = glm::lookAt(glm::vec3(camX, 0.0f, camZ), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    Orion::setUniformMat4fv(shaderProgram, "view", view_mat);
    
    Orion::bind_vertex_array(VAO_cube);
    for (unsigned int i = 0; i < 10; i++)
    {
        // calculate the model matrix for each object and pass it to shader before drawing
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, cubePositions[i]);
        float angle = 20.0f * i;
        model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
        Orion::setUniformMat4fv(shaderProgram, "model", model);

        Orion::draw((unsigned int)(Orion::default_cube_size / sizeof(float)));
    }

    glfwSwapBuffers(orion_window->window);
    glfwPollEvents();
  }

  Orion::destroy_shader(shaderProgram);
  Orion::destroy_window(orion_window);

  return 0;
}