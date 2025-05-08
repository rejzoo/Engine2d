#pragma once

#include "KeyBindings.h"
#include "Input.h"

class ActionMapper
{
private:
	const KeyBindings& m_bindings;
	const Input& m_input;

	ActionMapper(const KeyBindings& bindings, const Input& input);
	~ActionMapper();

	bool ActionDown(Action action) const;
	bool ActionPressed(Action action) const;

public:

};

