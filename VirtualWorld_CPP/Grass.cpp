#include "Grass.h"
#include "Config.h"
#include "World.h"

Grass::Grass(World* world, OrganismPositon organismPositon)
	:Plant(world, cfg::GRASS_STRENGTH, cfg::GRASS_INITIATIVE, organismPositon, cfg::GRASS_SYMBOL, "Trawa")
{
}

Grass::~Grass()
{
}



void Grass::sow(const OrganismPositon& organismPosition)
{
	world->pushOrganism(new Grass(world, organismPosition));

}

