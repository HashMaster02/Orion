#include "glad/glad.h"
#include "Orion/Input.h"

namespace Orion {
  void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
      glfwSetWindowShouldClose(window, 1);
  }

  // DOES NOT UPDATE ORION WINDOW PARAMETERS
  void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
  }
}