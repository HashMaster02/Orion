#pragma once
#include <GLFW/glfw3.h>
#include "Orion/Event.h"

namespace Orion {
    extern int Running;
    struct Window {
        GLFWwindow* window;
        int width;
        int height;
        const char* title;

        void(* GLFWframebuffersizefun) (GLFWwindow *window, int width, int height);
        void(* GLFWcursorposfun) (GLFWwindow *window, double xpos, double ypos);
    };

    void create_window(Orion::Window *window_params);

    void destroy_window(Orion::Window *myWindow);
    void close_window(const Event& event, void* userData);

    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    void cursor_callback(GLFWwindow* window, double xpos, double ypos);
}