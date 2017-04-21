#include "Plant.h"


void Plant::act()
{
}

Plant::Plant(World* world, unsigned short strength, unsigned short initiative, OrganismPositon organismPositon, const char symbol)
	:Organism(world, strength, initiative, organismPositon, symbol)
{
}

Plant::~Plant()
{
}
