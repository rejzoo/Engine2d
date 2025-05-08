#pragma once
#include <unordered_map>
#include <string>
#include <vector>
#include <fstream>
#include <nlohmann/json.hpp>

#include "Logger.h"
#include "InputActions.h"

enum class KeySection {
	MOVEMENT
};

class KeyBindings
{
private:
	std::unordered_map<KeySection, std::unordered_map<MovementAction, std::vector<int>>> bindings;

public:
	KeyBindings();

private:
	void LoadFromJson();
	KeySection SectionFromString(const std::string& section);
	MovementAction MoveActionFromString(const std::string& action);
};

