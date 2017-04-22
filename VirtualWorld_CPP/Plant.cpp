#include "Plant.h"


void Plant::act()
{
}

Plant::Plant(World* world, unsigned short strength, unsigned short initiative, OrganismPositon organismPositon, const char symbol, std::string name)
	:Organism(world, strength, initiative, organismPositon, symbol, name)
{
}

Plant::~Plant()
{
}
