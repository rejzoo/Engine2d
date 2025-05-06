#pragma once

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>

#include "Shader.h"
#include "Window.h"
#include "ConfigFile.h"
#include "Camera2D.h"

class Renderer2D
{
private:
	GLuint m_qVAO, m_qVBO;
	Shader* m_shader;
	Camera2D* m_camera;

public:
	Renderer2D(Camera2D* camera);
	~Renderer2D();
	void Draw(glm::vec2 position, glm::vec2 size, glm::vec4 color);

private:
	void InitQuad();

};
