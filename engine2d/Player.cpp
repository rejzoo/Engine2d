#include "Player.h"

Player::Player() : GameObject()
{
	
}

Player::Player(int posX, int posY, int width, int height)
	: GameObject(posX, posY, width, height)
{

}

void Player::Move(float dt, int deltaX, int deltaY)
{
	glm::vec2 cords = GetPosition();
	cords.x += dt * deltaX * m_speed;
	cords.y += dt * deltaY * m_speed;

	SetPosition(cords);
}
