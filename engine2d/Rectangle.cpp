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

void Rectangle::SetRotation(float rotation)
{
	m_rotation = rotation;
}

void Rectangle::Draw(Renderer2D* renderer) const
{
	glm::vec2 origin = (m_pivot == PivotMode::CENTER)
		? (m_size * 0.5f) : glm::vec2(0.0f, 0.0f);

	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(m_position + origin, 0.0f));
	model = glm::rotate(model, glm::radians(m_rotation), glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::translate(model, glm::vec3(-origin, 0.0f));
	model = glm::scale(model, glm::vec3(m_size, 1.0f));

	renderer->Draw(model, m_color);
}
