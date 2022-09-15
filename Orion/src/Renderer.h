#pragma once

#include "Window.h"

class Renderer : public Window
{
public:
	bool is_Running;
public:
	Renderer();
	~Renderer();
	void Draw();
	void SetBuffers();
};
