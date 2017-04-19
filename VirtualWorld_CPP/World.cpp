#include "World.h"
#include "Console.h"

World::World(string name, short x, short y, WindowPosition areaPos, WindowPosition reporterPos)
: reporter(new Reporter), areaPos(areaPos), reporterPos(reporterPos), width(x), height(y)
{
	randomize();

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

uint8_t World::getRandomNumber(uint8_t floor, uint8_t ceiling)
{
	return rand() % ceiling + floor;
}

void World::randomize()
{

}

uint8_t World::getWidth()
{
	return width;
}

uint8_t World::getHeight()
{
	return height;
}
