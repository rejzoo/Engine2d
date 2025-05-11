#include "GameObject.h"

GameObject::GameObject() : Rectangle()
{
}

GameObject::GameObject(int posX, int posY, int width, int height)
	: Rectangle(posX, posY, width, height)
{
}

GameObject::~GameObject()
{
}
