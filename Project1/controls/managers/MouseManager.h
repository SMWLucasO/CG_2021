#pragma once

#include <map>

#include "../../command/Command.h"

class MouseManager
{
private:
	std::map<unsigned short, Command*> commands;
};

