#include "PlayerController.h"

PlayerController::PlayerController() : m_actionMapper(ActionMapper::Instance())
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
	if (m_actionMapper.ActionDown(Action::MOVE_UP))
	{
		Logger::Log(LogType::DEBUG, "MOVE UP");
	} 
	else if (m_actionMapper.ActionDown(Action::MOVE_DOWN))
	{
		Logger::Log(LogType::DEBUG, "MOVE DOWN");
	}
	
	if (m_actionMapper.ActionDown(Action::MOVE_LEFT))
	{
		Logger::Log(LogType::DEBUG, "MOVE LEFT");
	}
	else if (m_actionMapper.ActionDown(Action::MOVE_RIGHT))
	{
		Logger::Log(LogType::DEBUG, "MOVE RIGHT");
	}
}
