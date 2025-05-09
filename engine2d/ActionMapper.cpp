#include "ActionMapper.h"

void ActionMapper::Init(Input* input)
{
	if (!m_input)
	{
		m_input = input;
	}
}

bool ActionMapper::ActionDown(Action action) const
{
	for (int key : m_bindings.GetKeys(KeySection::MOVEMENT, action))
	{
		if (m_input->KeyHeld(key))
		{
			return true;
		}
	}

	return false;
}

bool ActionMapper::ActionPressed(Action action) const
{
	for (int key : m_bindings.GetKeys(KeySection::MOVEMENT, action))
	{
		if (m_input->KeyPressed(key))
		{
			return true;
		}
	}

	return false;
}
