#include "Core.h"

class Window
{
public:
	struct WindowProperties
	{
		unsigned int Width;
		unsigned int Height;
		const char* Title;
	};
public:
	GLFWwindow* window;
public:
	virtual void OnUpdate() = 0;
	virtual bool IsRunning() = 0;
	virtual GLFWwindow* Create() = 0;

};
