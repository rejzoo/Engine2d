#include "PlayerController.h"

PlayerController::PlayerController() : m_actionMapper(InputActionMapper::Instance())
{
}

void PlayerController::Controll(Player* player)
{
	m_player = player;
}

void PlayerController::Update(float dt)
{
	UpdateMovement(dt);
}

void PlayerController::UpdateMovement(float dt)
{
	int deltaX = 0;
	int deltaY = 0;

	/*if (m_actionMapper.ActionDown(KeySection::MOVEMENT, Action::MOVE_UP))
	{
		deltaY = 1;
	} 
	else if (m_actionMapper.ActionDown(KeySection::MOVEMENT, Action::MOVE_DOWN))
	{
		deltaY = -1;
	}
	
	if (m_actionMapper.ActionDown(KeySection::MOVEMENT, Action::MOVE_LEFT))
	{
		deltaX = -1;
	}
	else if (m_actionMapper.ActionDown(KeySection::MOVEMENT, Action::MOVE_RIGHT))
	{
		deltaX = 1;
	}*/

	m_player->Move(dt, deltaX, deltaY);
}
