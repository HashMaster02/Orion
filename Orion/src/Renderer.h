#include "Window.h"

class Renderer : public Window
{
private:
	bool isRunning;
public:
	Renderer();
	GLFWwindow* Create() override;
	void OnUpdate() override;
	bool IsRunning() override;
};
