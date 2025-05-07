#pragma once

#include <glm/glm.hpp>

#include "Renderer2D.h"

class Logger;

class Rectangle
{
private:
	glm::vec2 m_position;
	glm::vec2 m_size;
	glm::vec4 m_color;

public:
	Rectangle(int posX, int posY, int width, int height);
	~Rectangle();

	glm::vec2 GetPosition() const { return m_position; }
	glm::vec2 GetSize() const { return m_size; }

	void Draw(Renderer2D& renderer) const;
};

