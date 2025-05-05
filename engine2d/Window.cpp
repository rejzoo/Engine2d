#include "Window.h"

Window::Window()
{
	m_width = 800;
	m_height = 800;
	m_mainWindow = nullptr;
	m_input = nullptr;
}

Window::Window(GLuint width, GLuint height) : m_width(width), m_height(height)
{
	m_mainWindow = nullptr;
	m_input = nullptr;
}

Window::~Window()
{
	delete m_mainWindow;
	delete m_input;
}


bool Window::ShouldClose()
{
	return glfwWindowShouldClose(m_mainWindow);
}

int Window::Init()
{
	
	if (!glfwInit())
	{
		Logger::Log(LogType::ERROR, "GLFW init failed.");
		glfwTerminate();
		return 1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	m_mainWindow = glfwCreateWindow(m_width, m_height, "engine2d", NULL, NULL);

	if (!m_mainWindow)
	{
		Logger::Log(LogType::ERROR, "Window creation failed.");
		glfwTerminate();
		return 1;
	}

	m_input = new Input(m_mainWindow);
	glfwSetWindowUserPointer(m_mainWindow, m_input);

	glfwMakeContextCurrent(m_mainWindow);

	if (glewInit() != GLEW_OK)
	{
		Logger::Log(LogType::ERROR, "GLEW init failed.");
		glfwDestroyWindow(m_mainWindow);
		glfwTerminate();
		return 1;
	}

	glViewport(0, 0, m_width, m_height);
	
	return 0;
}

void Window::SwapBuffers()
{
	glfwSwapBuffers(m_mainWindow);
}
