#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Logger.h"

class Input
{
private:
	bool m_keys[1024];

	GLFWwindow* m_mainWindow;

public:
	Input(GLFWwindow* window);
	bool KeyPressed(unsigned int key) const;
	
private:
	void CreateCallBacks();
	static void HandleKeys(GLFWwindow* window, int key, int code, int action, int mode);
	static void HandleMouse(GLFWwindow* window, double xPos, double yPos);
};

