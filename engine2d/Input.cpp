#include "Input.h"
#include "Window.h"

Input::Input(Window* window) : m_mainWindow(window)
{
	for (int i = 0; i < 1024; i++)
	{
		m_keys[i] = 0;
	}

	for (int i = 0; i < 1024; i++)
	{
		m_keysHeld[i] = 0;
	}

	CreateCallBacks();
}

bool Input::KeyPressed(unsigned int key) const
{
	if (key >= 1024)
	{
		std::string message = key + " is out of range.";
		Logger::Log(LogType::ERROR, message);
		return 0;
	}

	return m_keys[key];
}

bool Input::KeyHeld(unsigned int key) const
{
	if (key >= 1024)
	{
		std::string message = key + " is out of range.";
		Logger::Log(LogType::ERROR, message);
		return 0;
	}

	return m_keysHeld[key];
}

void Input::ResetMouseScrollData()
{
	m_mScrollY = 0;
}

void Input::ResetKeyPressed()
{
	for (int i = 0; i < 1024; i++)
	{
		m_keys[i] = 0;
	}
}

void Input::CreateCallBacks()
{
	glfwSetKeyCallback(m_mainWindow->GetGLFWWindow(), HandleKeys);
	glfwSetCursorPosCallback(m_mainWindow->GetGLFWWindow(), HandleMouse);
	glfwSetScrollCallback(m_mainWindow->GetGLFWWindow(), HandleScroll);
}

void Input::HandleKeys(GLFWwindow* window, int key, int code, int action, int mode)
{
	Window* mainWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));
	if (!mainWindow)
	{
		Logger::Log(LogType::ERROR, "Window NULL");
		return;
	}

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}

	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
		{
			if (!mainWindow->GetInput()->m_keysHeld[key]) {
				mainWindow->GetInput()->m_keys[key] = 1;
			}
			mainWindow->GetInput()->m_keysHeld[key] = 1;
		}
		else if (action == GLFW_RELEASE)
		{
			mainWindow->GetInput()->m_keysHeld[key] = 0;
		}
	}
}

void Input::HandleMouse(GLFWwindow* window, double xPos, double yPos)
{
	Window* mainWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));
	if (!mainWindow)
	{
		Logger::Log(LogType::ERROR, "Window NULL");
		return;
	}

	if (mainWindow->GetInput()->m_mouseFirstMoved)
	{
		mainWindow->GetInput()->m_lastX = xPos;
		mainWindow->GetInput()->m_lastY = yPos;
		mainWindow->GetInput()->m_mouseFirstMoved = false;
	}

	mainWindow->GetInput()->m_xChange = xPos - mainWindow->GetInput()->m_lastX;
	mainWindow->GetInput()->m_yChange = mainWindow->GetInput()->m_lastY - yPos;

	mainWindow->GetInput()->m_lastX = xPos;
	mainWindow->GetInput()->m_lastY = yPos;
}

void Input::HandleScroll(GLFWwindow* window, double xOffset, double yOffset)
{
	Window* mainWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));
	if (!mainWindow)
	{
		Logger::Log(LogType::ERROR, "Window NULL");
		return;
	}

	mainWindow->GetInput()->m_mScrollY = yOffset;
}
