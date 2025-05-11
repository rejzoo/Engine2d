#pragma once

#include <glm/glm.hpp>

#include "Renderer2D.h"

class Logger;

enum class PivotMode {
	DEFAULT,
	CENTER
};

class Rectangle
{
private:
	glm::vec2 m_position;
	glm::vec2 m_size;
	glm::vec4 m_color;
	float m_rotation = 0.0f;
	PivotMode m_pivot { PivotMode::CENTER };

public:
	Rectangle();
	Rectangle(int posX, int posY, int width, int height);
	~Rectangle();

	glm::vec2 GetPosition() const { return m_position; }
	glm::vec2 GetSize() const { return m_size; }
	void SetPosition(glm::vec2 position);
	void SetRotation(float rotation);

	void Draw(Renderer2D* renderer) const;
};

