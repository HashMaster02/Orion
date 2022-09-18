#include "Window.h"

class Renderer : public Window
{
private:
	bool isRunning;
	WindowProperties props;
public:
	Renderer();
	Renderer(int w, int h, const char* t);
	GLFWwindow* Create(WindowProperties props) override;
	void OnUpdate() override;
	bool IsRunning() override;
};
