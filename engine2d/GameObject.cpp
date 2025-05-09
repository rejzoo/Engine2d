#include "GameObject.h"

GameObject::GameObject()
{
	m_sprite = new Rectangle();
}

GameObject::GameObject(int posX, int posY, int width, int height)
{
	m_sprite = new Rectangle(posX, posY, width, height);
}

GameObject::~GameObject()
{
	delete m_sprite;
}

glm::vec2 GameObject::GetPosition() const
{
	return m_sprite->GetPosition();
}

glm::vec2 GameObject::GetSize() const
{
	return m_sprite->GetSize();
}

void GameObject::SetPosition(glm::vec2 position)
{
	m_sprite->SetPosition(position);
}

void GameObject::Draw(Renderer2D* renderer)
{
	m_sprite->Draw(renderer);
}
