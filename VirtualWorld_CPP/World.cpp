#include "World.h"
#include "Console.h"


World::World(string name, short x, short y) : name(name), x(x), y(y), overallTime(0), currentSessionTime(0)
{
	reporter = new Reporter();
	//Zrób organizmy
}

World::~World()
{
	delete reporter;
}

void World::playRound()
{
	//TODO: do backend gaming stuff, game internals
}

void World::drawArea(const WindowPosition& window_position)
{

}

