#include "Renderer.h"


Renderer::Renderer()
{
    this->window = Create();
}

GLFWwindow* Renderer::Create()
{
    WindowProperties props;
    props.Width = 1280;
    props.Height = 720;
    props.Title = "Test Window";

    if (!isRunning) {
        glfwInit();
        isRunning = true;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    this->window = glfwCreateWindow(props.Width, props.Height, props.Title, NULL, NULL);
   
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }

    glfwMakeContextCurrent(window);
    return window;
}

void Renderer::OnUpdate()
{
    glfwSwapBuffers(this->window);
    glfwPollEvents();
}

bool Renderer::IsRunning()
{
	return isRunning;
}
