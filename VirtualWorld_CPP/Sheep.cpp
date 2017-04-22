#include "Sheep.h"
#include "Config.h"


Sheep::Sheep(World* world, OrganismPositon organismPositon)
	:Animal(world, cfg::SHEEP_STRENGTH, cfg::SHEEP_INITIATIVE, organismPositon, cfg::SHEEP_SYMBOL, "Owca")
{
}

Sheep::~Sheep()
{
}

void Sheep::handleCollision(Organism*)
{
}

