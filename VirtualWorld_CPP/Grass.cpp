#include "Grass.h"
#include "Config.h"


Grass::Grass(World* world, OrganismPositon organismPositon)
	:Plant(world, cfg::GRASS_STRENGTH, cfg::GRASS_INITIATIVE, organismPositon, cfg::GRASS_SYMBOL, "Trawa")
{
}

Grass::~Grass()
{
}

void Grass::handleCollision(Organism*)
{
}

