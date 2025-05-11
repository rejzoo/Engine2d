#pragma once

#include <unordered_map>
#include <vector>
#include <nlohmann/json.hpp>
#include <fstream>

#include "Exceptions.h"
#include "Input.h"
#include "Actions.h"

enum class KeySection {
	MOVEMENT
};

class InputActionMapper
{
private:
	const Input* m_input = nullptr;

	std::unordered_map<KeySection, std::unordered_map<Action, std::vector<int>>> m_bindings;

public:
	InputActionMapper(const InputActionMapper&) = delete;
	InputActionMapper& operator=(InputActionMapper&) = delete;
	~InputActionMapper();

	static InputActionMapper& Instance() {
		static InputActionMapper instance;
		return instance;
	}

	void Init(Input* input);
	bool ActionDown(KeySection section, Action action) const;
	bool ActionPressed(KeySection section, Action action) const;
	// TODO MB NEED TO ADD KEYDOWN AND ACTION DOWN

private:
	InputActionMapper() {}

	std::vector<int> GetKeys(KeySection section, Action action) const;

	void LoadFromJson();
	KeySection SectionFromString(const std::string& section);
	Action ActionFromString(const std::string& action);
};
