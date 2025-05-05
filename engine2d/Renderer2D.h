#pragma once

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>

#include "Shader.h"

class Renderer2D
{
private:
	GLuint m_qVAO, m_qVBO;
	Shader* m_shader;

public:
	Renderer2D();
	~Renderer2D();
	void Draw(glm::vec2 position, glm::vec2 size, glm::vec4 color);

private:
	void InitQuad();

};
