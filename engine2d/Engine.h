#pragma once

#include "Logger.h"
#include "Window.h"
#include "Renderer2D.h"
#include "Rectangle.h"

class Engine
{
private:
	Window* m_window;
	Renderer2D* m_renderer;

public:
	Engine();
	~Engine();

	void Run();
	Renderer2D* GetRenderer() { return m_renderer; }
};

