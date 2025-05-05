#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Logger.h"
#include "Input.h"

class Window
{
private:
	GLFWwindow* m_mainWindow;
	Input* m_input;
	
	GLuint m_width, m_height;

public:
	Window();
	Window(GLuint width, GLuint height);
	~Window();

	bool ShouldClose();
	int Init();
	void SwapBuffers();

private:

};

