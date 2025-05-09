#pragma once

#include "GameObject.h"

class Player : public GameObject
{
private:
	int m_speed = 200;

public:
	Player();
	Player(int posX, int posY, int width, int height);

	void Move(float dt, int deltaX, int deltaY);
};
