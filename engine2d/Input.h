#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Logger.h"

class Window;

class Input
{
private:
	bool m_keys[1024];

	// Mouse
	GLfloat m_lastX;
	GLfloat m_lastY;
	GLfloat m_xChange;
	GLfloat m_yChange;
	bool m_mouseFirstMoved;
	GLfloat m_mScrollY;

	Window* m_mainWindow;

public:
	Input(Window* window);
	bool KeyPressed(unsigned int key) const;
	GLfloat GetMouseX() const { return m_lastX; }
	GLfloat GetMouseY() const { return m_lastY; }
	GLfloat GetMouseScrollY() const { return m_mScrollY; }

	void ResetMouseScrollData();
	
private:
	void CreateCallBacks();
	static void HandleKeys(GLFWwindow* window, int key, int code, int action, int mode);
	static void HandleMouse(GLFWwindow* window, double xPos, double yPos);
	static void HandleScroll(GLFWwindow* window, double xOffset, double yOffset);
};
