#pragma once
#include <unordered_map>
#include <string>
#include <vector>
#include <fstream>
#include <nlohmann/json.hpp>

#include "Logger.h"
#include "Actions.h"
#include "Exceptions.h"


enum class KeySection {
	MOVEMENT
};

class KeyBindings
{
private:
	std::unordered_map<KeySection, std::unordered_map<Action, std::vector<int>>> m_bindings;

public:
	KeyBindings(const KeyBindings&) = delete;
	KeyBindings& operator=(const KeyBindings&) = delete;
	static KeyBindings& Instance() {
		static KeyBindings instance;
		return instance;
	}

	std::vector<int> GetKeys(KeySection section, Action action) const;

private:
	KeyBindings();
	~KeyBindings() {};
	void LoadFromJson();
	KeySection SectionFromString(const std::string& section);
	Action ActionFromString(const std::string& action);
};

