#include "Engine.h"

Engine::Engine()
{
	m_window = new Window();
	m_window->Init();

	m_input = new Input(m_window->GetGLFWWindow());
	m_window->SetInput(m_input);

	m_camera = new Camera2D();
	m_renderer = new Renderer2D(m_camera);

}

Engine::~Engine()
{
	Logger::Log(LogType::MESSAGE, "Engine Stopped.");
	delete m_window;
	delete m_renderer;
	delete m_input;
}

void Engine::Run()
{
	Logger::Log(LogType::MESSAGE, "Engine Started.");

	Rectangle obj1(0, 0, 100, 100);

	GLfloat dt = 0, lastTime = 0;

	while (!m_window->ShouldClose())
	{
		GLfloat now = glfwGetTime();
		dt = now - lastTime;
		lastTime = now;

		glClear(GL_COLOR_BUFFER_BIT);

		obj1.Draw(*m_renderer);
		m_camera->Update(dt, { m_input->GetMouseX(), m_input->GetMouseY() });

		m_window->SwapBuffers();
		glfwPollEvents();
	}
}
