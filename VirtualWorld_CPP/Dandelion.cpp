#include "Dandelion.h"
#include "Config.h"
#include "World.h"

Dandelion::Dandelion(World* world, OrganismPositon organismPositon)
	:Plant(world, cfg::DANDELION_STRENGTH, cfg::DANDELION_INITIATIVE, organismPositon, cfg::DANDELION_SYMBOL, "Mlecz")
{
}

Dandelion::~Dandelion()
{
}


void Dandelion::act()
{
	for (int i = 0; i < cfg::DANDELION_SOW_ATTEMPT_NUMBER; ++i)
	{
		Plant::act();
	}
}

void Dandelion::sow(const OrganismPositon& organismPosition)
{
	world->pushOrganism(new Dandelion(world, organismPosition));
}

