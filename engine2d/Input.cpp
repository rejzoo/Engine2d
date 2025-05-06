#include "Input.h"

Input::Input(GLFWwindow* window) : m_mainWindow(window)
{
	for (int i = 0; i < 1024; i++)
	{
		m_keys[i] = 0;
	}

	CreateCallBacks();
}

bool Input::KeyPressed(unsigned int key) const
{
	if (key >= 1024)
	{
		std::string message = key + " is out of range.";
		Logger::Log(LogType::WARNING, message);
		return 0;
	}

	return m_keys[key];
}

void Input::CreateCallBacks()
{
	glfwSetKeyCallback(m_mainWindow, HandleKeys);
	glfwSetCursorPosCallback(m_mainWindow, HandleMouse);
}

void Input::HandleKeys(GLFWwindow* window, int key, int code, int action, int mode)
{
	Input* input = static_cast<Input*>(glfwGetWindowUserPointer(window));
	if (!input)
	{
		Logger::Log(LogType::ERROR, "Input NULL");
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
			Logger::Log(LogType::DEBUG, std::to_string(key));
			input->m_keys[key] = 1;
		}
		else if (action == GLFW_RELEASE)
		{
			input->m_keys[key] = 0;
		}
	}
}

void Input::HandleMouse(GLFWwindow* window, double xPos, double yPos)
{
	Input* input = static_cast<Input*>(glfwGetWindowUserPointer(window));

	if (input->m_mouseFirstMoved)
	{
		input->m_lastX = xPos;
		input->m_lastY = yPos;
		input->m_mouseFirstMoved = false;
	}

	input->m_xChange = xPos - input->m_lastX;
	input->m_yChange = input->m_lastY - yPos;

	input->m_lastX = xPos;
	input->m_lastY = yPos;
}
