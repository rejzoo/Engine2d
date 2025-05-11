#pragma once

#include "Window.h"
#include "Renderer2D.h"
#include "Rectangle.h"
#include "Camera2D.h"
#include "Input.h"
#include "InputActionMapper.h"
#include "PlayerController.h"
#include "Player.h"

class Logger;

class Engine
{
private:
	Window* m_window;
	Renderer2D* m_renderer;
	Input* m_input;
	Camera2D* m_camera;
	PlayerController* m_playerController;

public:
	Engine();
	~Engine();

	void Run();
	Renderer2D* GetRenderer() { return m_renderer; }

private:
	void Init();
	void Update(float dt);
	void Draw(float dt);
};

