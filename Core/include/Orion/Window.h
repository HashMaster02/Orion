#pragma once
#include <GLFW/glfw3.h>

namespace Orion {
    struct Window {
        GLFWwindow* window;
        int width;
        int height;
        const char* title;

        void(* GLFWframebuffersizefun) (GLFWwindow *window, int width, int height);
    };

    void create_window(Orion::Window *window_params);

    void destroy_window(Orion::Window *myWindow);
    int close_window(Orion::Window *myWindow);
}