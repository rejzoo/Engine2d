#pragma once

#include "Logger.h"
#include "Window.h"
#include "Renderer2D.h"
#include "Rectangle.h"
#include "Camera2D.h"

class Engine
{
private:
	Window* m_window;
	Renderer2D* m_renderer;
	Input* m_input;
	Camera2D* m_camera;

public:
	Engine();
	~Engine();

	void Run();
	Renderer2D* GetRenderer() { return m_renderer; }
};

