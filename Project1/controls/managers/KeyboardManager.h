#pragma once

#include <map>

#include "../../command/Command.h"

class KeyboardManager
{
private:
	std::map<unsigned short, Command*> commands;
};

