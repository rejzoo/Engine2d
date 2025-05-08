#include "KeyBindings.h"

KeyBindings::KeyBindings()
{
	LoadFromJson();
}

KeyBindings::~KeyBindings()
{
}

std::vector<int> KeyBindings::GetKeys(KeySection section, Action action) const
{
    return m_bindings.at(section).at(action);
}

void KeyBindings::LoadFromJson()
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
KeySection KeyBindings::SectionFromString(const std::string& section)
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
Action KeyBindings::ActionFromString(const std::string& action)
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
