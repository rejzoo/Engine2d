#include "KeyBindings.h"

KeyBindings::KeyBindings()
{
	LoadFromJson();
}

void KeyBindings::LoadFromJson()
{
    nlohmann::json root;
    std::ifstream in("KeyBindings.json");
    in >> root;

    for (auto& [sectionName, sectionValue] : root.items()) {
        KeySection sec = SectionFromString(sectionName);

        Logger::Log(LogType::DEBUG, sectionName);
        for (auto& [actionName, keysArray] : sectionValue.items()) {
            MovementAction act = MoveActionFromString(actionName);
            Logger::Log(LogType::DEBUG, "   " + actionName);

        std::vector<int> 
            /*auto& vec = bindings
                [static_cast<size_t>(sec)]
                [static_cast<size_t>(act)];

            for (int code : keysArray) {
                vec.push_back(code);
            }*/
        }
    }

    Logger::Log(LogType::DEBUG, "END");
}

KeySection KeyBindings::SectionFromString(const std::string& section)
{
    if (section == "MOVEMENT")
    {
        return KeySection::MOVEMENT;
    }
    
    Logger::Log(LogType::ERROR, "UNKNOWN SECTION: " + section);
}

MovementAction KeyBindings::MoveActionFromString(const std::string& action)
{
    if (action == "MOVE_UP")
    {
        return MovementAction::MOVE_UP;
    } 
    else if (action == "MOVE_DOWN")
    {
        return MovementAction::MOVE_DOWN;
    }
    else if (action == "MOVE_LEFT")
    {
        return MovementAction::MOVE_LEFT;

    }
    else if (action == "MOVE_RIGHT")
    {
        return MovementAction::MOVE_RIGHT;
    }

    Logger::Log(LogType::ERROR, "UNKNOWN ACTION: " + action);
}
