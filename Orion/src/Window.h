#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Window 
{
	public:
		GLFWwindow* m_Window;
		int m_Width;
		int m_Height;
		const char* m_Title;
	private:
		bool isInitialized = false;
	public:
		Window()
		{
			m_Width = 1280;
			m_Height = 720;
			m_Title = "Deafult Window";

			if (!isInitialized)
			{
				glfwInit();
				glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
				glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
				glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
			}

			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);

			if (m_Window == NULL)
			{
				std::cout << "Failed to create GLFW window" << std::endl;
				glfwTerminate();
			}

			MakeContextCurrent(m_Window);
		}

		Window(int w, int h, const char* title)
		{
			m_Width = w;
			m_Height = h;
			m_Title = title;

			glfwInit();
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);

			if (m_Window == NULL)
			{
				std::cout << "Failed to create GLFW window" << std::endl;
				glfwTerminate();
			}

			MakeContextCurrent(m_Window);
		}

		~Window()
		{
			glfwTerminate();
		}

		void MakeContextCurrent(GLFWwindow* window)
		{
			glfwMakeContextCurrent(window);
		}

	private:
		inline int getWidth() { return m_Width; };
		inline int getHegiht() { return m_Height; };

		//void sizeCallback(GLFWwindow* window, int width, int height);
};

