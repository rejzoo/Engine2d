#pragma once

#include <glm/glm.hpp>

#include "Renderer2D.h"
#include "Logger.h"

class Rectangle
{
private:
	glm::vec2 m_position;
	glm::vec2 m_size;
	glm::vec4 m_color;

public:
	Rectangle(int posX, int posY, int width, int height);
	void Draw(Renderer2D& renderer) const;
	~Rectangle();
};

