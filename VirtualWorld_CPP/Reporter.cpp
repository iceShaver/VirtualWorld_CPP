#include "Reporter.h"
#include <iostream>
Reporter::Reporter(World* world, WindowPosition winPos)
	:world(world), winPos(winPos)
{
}

void Reporter::newMessage(std::string message, const Organism* organism, const Organism*otherOrganism)
{
	if (organism)
		message = organism->toString() + ": "+message;
	if (otherOrganism)
		message += otherOrganism->toString();
	messages.push_front(message);
}


void Reporter::printMessages()
{
	uint8_t x = winPos.x;
	void(*prevLine)(uint8_t) = Console::prevLine;
	Console::setCursorPos({winPos.x, uint8_t(winPos.y+winPos.height-2)});
	int i = 1;
	for (auto message : messages)
	{
		cout << message;
		i++;
		if (i>=winPos.height) break;
		prevLine(x);
	}
}
