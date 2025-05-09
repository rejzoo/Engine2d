#pragma once

#include "Rectangle.h"

class GameObject
{
protected:
	Rectangle* m_sprite;

public:
	GameObject();
	GameObject(int posX, int posY, int width, int height);
	~GameObject();

	glm::vec2 GetPosition() const;
	glm::vec2 GetSize() const;
	void SetPosition(glm::vec2 position);

	void Draw(Renderer2D* renderer);
};
