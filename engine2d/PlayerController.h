#pragma once

#include "ActionMapper.h"
#include "Player.h"

class PlayerController
{
private:
	ActionMapper& m_actionMapper;
	Player* m_player = nullptr;

public:
	PlayerController();
	void Controll(Player* player);

	void Update(float dt);

private:
	void UpdateMovement(float dt);
};
