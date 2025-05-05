#include "Rectangle.h"

Rectangle::Rectangle(int posX, int posY, int width, int height)
{
	m_position = glm::vec2(posX, posY);
	m_size = glm::vec2(width, height);
	m_color = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
}

void Rectangle::Draw(Renderer2D& renderer) const
{
	renderer.Draw(m_position, m_size, m_color);
}

Rectangle::~Rectangle()
{
}
