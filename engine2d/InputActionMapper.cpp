#include "InputActionMapper.h"

InputActionMapper::~InputActionMapper()
{
    m_bindings.clear();
}

void InputActionMapper::Init(Input* input)
{
	if (!m_input)
	{
		m_input = input;
	}
    
    LoadFromJson();
}

bool InputActionMapper::ActionDown(KeySection section, Action action) const
{
	for (int key : GetKeys(section, action))
	{
		if (m_input->KeyHeld(key))
		{
			return true;
		}
	}

	return false;
}

bool InputActionMapper::ActionPressed(KeySection section, Action action) const
{
	for (int key : GetKeys(section, action))
	{
		if (m_input->KeyPressed(key))
		{
			return true;
		}
	}

	return false;
}

std::vector<int> InputActionMapper::GetKeys(KeySection section, Action action) const
{
    return m_bindings.at(section).at(action);
}

// TODO IS LEAKING IDK HOW AND WHERE
void InputActionMapper::LoadFromJson()
{
    Logger::Log(LogType::MESSAGE, "Started loading keybindings.");

    nlohmann::json root;
    std::ifstream in("KeyBindings.json");
    in >> root;

    for (auto& [sectionName, sectionValue] : root.items())
    {
        KeySection section = SectionFromString(sectionName);

        for (auto& [actionName, keysArray] : sectionValue.items())
        {
            Action action = ActionFromString(actionName);

            std::vector<int> keys;

            for (int code : keysArray)
            {
                keys.push_back(code);
            }

            if (m_bindings.find(section) == m_bindings.end())
            {
                std::unordered_map<Action, std::vector<int>> innerMap;
                innerMap.emplace(action, std::move(keys));

                m_bindings.emplace(section, std::move(innerMap));
            }
            else
            {
                auto& innerMap = m_bindings.find(section)->second;
                innerMap.emplace(action, std::move(keys));
            }
        }
    }

    Logger::Log(LogType::MESSAGE, "Finished loading keybindings.");
}

// I DONT LIKE THIS, IF YOU SEE THIS FEEL AND KNOW BETTER 
// FREE TO TELL ME, I WANT TO LEARN
KeySection InputActionMapper::SectionFromString(const std::string& section)
{
    if (section == "MOVEMENT")
    {
        return KeySection::MOVEMENT;
    }

    Logger::Log(LogType::ERROR, "UNKNOWN SECTION: " + section);
    throw UnknownSectionException(section);
}

// I DONT LIKE THIS, IF YOU SEE THIS FEEL AND KNOW BETTER 
// FREE TO TELL ME, I WANT TO LEARN
Action InputActionMapper::ActionFromString(const std::string& action)
{
    if (action == "MOVE_UP")
    {
        return Action::MOVE_UP;
    }
    else if (action == "MOVE_DOWN")
    {
        return Action::MOVE_DOWN;
    }
    else if (action == "MOVE_LEFT")
    {
        return Action::MOVE_LEFT;

    }
    else if (action == "MOVE_RIGHT")
    {
        return Action::MOVE_RIGHT;
    }

    Logger::Log(LogType::ERROR, "UNKNOWN ACTION: " + action);
    throw UnknownActionException(action);
}
