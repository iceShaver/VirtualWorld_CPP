#include "DeadlyNightshade.h"
#include "Config.h"
#include "World.h"

DeadlyNightshade::DeadlyNightshade(World* world, OrganismPositon organismPositon)
	:Plant(world, cfg::DEADLY_NIGHTSHADE_STRENGTH, cfg::DEADLY_NIGHTSHADE_INITIATIVE,
		organismPositon, cfg::DEADLY_NIGHTSHADE_SYMBOL, "Wilcza jagoda")
{
}

DeadlyNightshade::~DeadlyNightshade()
{
}

Organism::ResistType DeadlyNightshade::resistsAttack(const Organism* otherOrganism)
{
	return kill;
}


void DeadlyNightshade::sow(const OrganismPositon& organismPosition)
{
	world->pushOrganism(new DeadlyNightshade(world, organismPosition));

}

