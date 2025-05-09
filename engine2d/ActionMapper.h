#pragma once

#include "KeyBindings.h"
#include "Input.h"

class ActionMapper
{
private:
	const KeyBindings& m_bindings;
	const Input* m_input = nullptr;

public:
	static ActionMapper& Instance() {
		static ActionMapper instance;
		return instance;
	}
	void Init(Input* input);
	bool ActionDown(Action action) const;
	bool ActionPressed(Action action) const;

private:
	ActionMapper() : m_bindings(KeyBindings::Instance()) {}
};
