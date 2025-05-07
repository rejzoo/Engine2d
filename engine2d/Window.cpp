#include "Window.h"

Window::Window()
{
	m_width = EngineConfig::WINDOW_WIDTH;
	m_height = EngineConfig::WINDOW_HEIGHT;
	m_mainWindow = nullptr;
	m_input = nullptr;
}

Window::~Window()
{
}


bool Window::ShouldClose()
{
	return glfwWindowShouldClose(m_mainWindow);
}

void Window::SetInput(Input* input)
{
	m_input = input;
	glfwSetWindowUserPointer(m_mainWindow, m_input);
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
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	//glfwWindowHint(GLFW_DECORATED, NULL); // Disable title bar

	m_mainWindow = glfwCreateWindow(m_width, m_height, "engine2d", NULL, NULL);

	if (!m_mainWindow)
	{
		Logger::Log(LogType::ERROR, "Window creation failed.");
		glfwTerminate();
		return 1;
	}

	glfwMakeContextCurrent(m_mainWindow);

	if (glewInit() != GLEW_OK)
	{
		Logger::Log(LogType::ERROR, "GLEW init failed.");
		glfwDestroyWindow(m_mainWindow);
		glfwTerminate();
		return 1;
	}

	glViewport(0, 0, m_width, m_height);
	
	glfwSetFramebufferSizeCallback(m_mainWindow, HandleResize);
	return 0;
}

void Window::SwapBuffers()
{
	glfwSwapBuffers(m_mainWindow);
}

void Window::HandleResize(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
