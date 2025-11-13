#include <glad/glad.h>
#include "Orion/Window.h"
#include <iostream>

namespace Orion {
  void create_window(Orion::Window *window_params) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(window_params->width, window_params->height, window_params->title, NULL, NULL);
    if (window == NULL) {
      printf("Failed to create GLFW window");
      glfwTerminate();
      return;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, window_params->GLFWframebuffersizefun);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
      printf("Failed to initialize GLAD");
      return;
    }
    glEnable(GL_DEPTH_TEST);
    window_params->window = window;

  }

  void destroy_window(Orion::Window *myWindow) {
      glfwDestroyWindow(myWindow->window);
  }

  int close_window(Orion::Window *myWindow) {
      return glfwWindowShouldClose(myWindow->window);
  }
}