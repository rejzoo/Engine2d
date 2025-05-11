#pragma once

#include "Rectangle.h"

class GameObject : public Rectangle
{
public:
	GameObject();
	GameObject(int posX, int posY, int width, int height);
	~GameObject();
};
