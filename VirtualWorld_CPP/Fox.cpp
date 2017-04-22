#include "Fox.h"
#include "Config.h"


Fox::Fox(World* world, OrganismPositon organismPositon)
	:Animal(world, cfg::FOX_STRENGTH, cfg::FOX_INITIATIVE, organismPositon, cfg::FOX_SYMBOL)
{
}

Fox::~Fox()
{
}

void Fox::handleCollision(Organism*other)
{
}

