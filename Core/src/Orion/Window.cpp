#include <glad/glad.h>
#include "Orion/Window.h"
#include <iostream>

namespace Orion {
  int Running = 1;

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
    glfwSetCursorPosCallback(window, window_params->GLFWcursorposfun);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
      printf("Failed to initialize GLAD");
      return;
    }
    glEnable(GL_DEPTH_TEST);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    window_params->window = window;

  }

  void destroy_window(Orion::Window *myWindow) {
      glfwDestroyWindow(myWindow->window);
  }

  void close_window(const Event& event, void* userData) {
    if (event.type == EVENT_KEY_PRESSED) {
      int keycode = event.data.key_pressed_data.GLFWKeyCode;
      if (keycode == GLFW_KEY_ESCAPE) {
        Running = 0;
      }
    }
  }

  void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) {
        Event evt;
        evt.type = EVENT_KEY_PRESSED;
        evt.data.key_pressed_data.GLFWKeyCode = key;
        dispatch_event(evt);
    }
  }

  void cursor_callback(GLFWwindow* window, double xpos, double ypos) {
    Event evt;
    evt.type = EVENT_MOUSE_CURSOR_MOVE;
    evt.data.mouse_move_data.xpos = static_cast<int>(xpos);
    evt.data.mouse_move_data.ypos = static_cast<int>(ypos);
    dispatch_event(evt);
  }
}