#include "Logger.h"

void Logger::Log(const LogType logType, const std::string& message)
{
    std::time_t t = std::time(nullptr);
    std::tm local{};
    localtime_s(&local, &t);
    
    std::string time = std::to_string(local.tm_hour) + ":" +
                        std::to_string(local.tm_min) + ":" +
                        std::to_string(local.tm_sec);
    auto [type, color] = GetValues(logType);

    std::cout << color << "[LOG - " << type << "] |" << time << "|  -  " << message << "\n";
}

std::tuple<std::string, std::string> Logger::GetValues(const LogType logType)
{
    switch (logType) {
        case LogType::MESSAGE:
            return { "MESSAGE", "\033[36m" };
        case LogType::DEBUG:
            return { "DEBUG",   "\033[32m" };
        case LogType::WARNING:
            return { "WARNING", "\033[33m" };
        case LogType::ERROR:
            return { "ERROR",   "\033[31m" };
        default:
            return { "UNKNOWN", "\033[0m" };
    }
}
