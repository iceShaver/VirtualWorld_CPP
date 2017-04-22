#pragma once
#include <string>
#include <list>
#include "World.h"
class World;
class Organism;
class Reporter
{
public:
	explicit Reporter(World * world, WindowPosition winPos);
	void newMessage(std::string message, const Organism*organism = nullptr);
	void printMessages();
private:
	std::list<std::string> messages;
	WindowPosition winPos;
	World * world;
};

