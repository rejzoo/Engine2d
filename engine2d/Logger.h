#pragma once
#include <string>
#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <tuple>

enum LogType
{
	MESSAGE,
	DEBUG,
	WARNING,
	ERROR
};

class Logger
{
private:

public:
	static void Log(const LogType logType, const std::string& message);

private:
	static std::tuple<std::string, std::string> GetValues(const LogType logType);
};

