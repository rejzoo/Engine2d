#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "ConfigFile.h"

class Logger;
class Input;

class Window
{
private:
	GLFWwindow* m_mainWindow;
	Input* m_input;
	
	GLuint m_width, m_height;

public:
	Window();
	~Window();

	bool ShouldClose();
	GLuint GetWidth() const { return m_width; }
	GLuint GetHeight() const { return m_height; }
	GLFWwindow* GetGLFWWindow() { return m_mainWindow; }
	Input* GetInput() { return m_input; }

	void SetInput(Input* input);

	int Init();
	void SwapBuffers();
	

private:
	static void HandleResize(GLFWwindow* window, int width, int height);
};