#include "Dandelion.h"
#include "Config.h"


Dandelion::Dandelion(World* world, OrganismPositon organismPositon)
	:Plant(world, cfg::DANDELION_STRENGTH, cfg::DANDELION_INITIATIVE, organismPositon, cfg::DANDELION_SYMBOL, "Mlecz")
{
}

Dandelion::~Dandelion()
{
}

void Dandelion::handleCollision(Organism*otherOrganism)
{
	Plant::handleCollision(otherOrganism);
}

