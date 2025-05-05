#include "Engine.h"

Engine::Engine()
{
	m_window = nullptr;
	m_renderer = nullptr;
}

Engine::~Engine()
{
	Logger::Log(LogType::MESSAGE, "Engine Stopped.");
	delete(m_window);
	delete(m_renderer);
}

void Engine::Run()
{
	Logger::Log(LogType::MESSAGE, "Engine Started.");

	m_window = new Window();
	m_window->Init();

	m_renderer = new Renderer2D();

	Rectangle obj1(350, 100, 60, 500);
	Rectangle obj2(150, 350, 500, 60);
	Rectangle obj3(350, 100, 300, 60);
	Rectangle obj4(590, 350, 60, 300);

	
	while (!m_window->ShouldClose())
	{
		glClear(GL_COLOR_BUFFER_BIT);

		obj1.Draw(*m_renderer);
		obj2.Draw(*m_renderer);
		obj3.Draw(*m_renderer);
		obj4.Draw(*m_renderer);

		m_window->SwapBuffers();
		glfwPollEvents();
	}
}
