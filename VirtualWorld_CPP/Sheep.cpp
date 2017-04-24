#include "Sheep.h"
#include "Config.h"
#include "World.h"

Sheep::Sheep(World* world, OrganismPositon organismPositon)
	:Animal(world, cfg::SHEEP_STRENGTH, cfg::SHEEP_INITIATIVE,
		organismPositon, cfg::SHEEP_SYMBOL, "Owca")
{
}

Sheep::~Sheep()
{
}

void Sheep::spawn(const OrganismPositon& organismPosition)
{
	world->pushOrganism(new Sheep(world, organismPosition));

}


