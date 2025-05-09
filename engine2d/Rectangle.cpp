#include "Rectangle.h"

Rectangle::Rectangle()
{
	m_position = glm::vec2(0.0f, 0.0f);
	m_size = glm::vec2(50.0f, 50.0f);
	m_color = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);
}

Rectangle::Rectangle(int posX, int posY, int width, int height)
{
	m_position = glm::vec2(posX, posY);
	m_size = glm::vec2(width, height);
	m_color = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);
}

Rectangle::~Rectangle()
{
}

void Rectangle::SetPosition(glm::vec2 position)
{
	m_position = position;
}

void Rectangle::Draw(Renderer2D* renderer) const
{
	renderer->Draw(m_position, m_size, m_color);
}
