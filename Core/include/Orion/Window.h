#pragma once
#include <GLFW/glfw3.h>

struct OrionWindow {
    GLFWwindow* window;
    int width;
    int height;
    const char* title;

    void(* GLFWframebuffersizefun) (GLFWwindow *window, int width, int height);
};

void create_window(OrionWindow *window_params);

void destroy_window(OrionWindow *myWindow);
int close_window(OrionWindow *myWindow);