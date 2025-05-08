#include "ActionMapper.h"

ActionMapper::ActionMapper(const KeyBindings & bindings, const Input & input)
	: m_bindings(bindings), m_input(input)
{

}

ActionMapper::~ActionMapper()
{
}

bool ActionMapper::ActionDown(Action action) const
{
	for (int key : m_bindings.GetKeys(KeySection::MOVEMENT, action))
	{
		if (m_input.KeyHeld(key))
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
		if (m_input.KeyPressed(key))
		{
			return true;
		}
	}

	return false;
}
