#pragma once

#include "InputActionMapper.h"
#include "Player.h"

class PlayerController
{
private:
	InputActionMapper& m_actionMapper;
	Player* m_player = nullptr;

public:
	PlayerController();
	void Controll(Player* player);

	void Update(float dt);

private:
	void UpdateMovement(float dt);
};
