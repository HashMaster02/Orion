#include "Renderer.h"

int main()
{
	Renderer renderer;

	while (renderer.IsRunning())
	{
		renderer.OnUpdate();
	}
	
}