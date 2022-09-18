#include "src/Renderer.h"

int main()
{
	Renderer renderer(1920, 1080, "Renderer");

	while (renderer.IsRunning())
	{
		renderer.OnUpdate();
	}

}