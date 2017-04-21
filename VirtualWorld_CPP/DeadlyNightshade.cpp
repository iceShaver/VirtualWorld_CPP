#include "DeadlyNightshade.h"
#include "Config.h"


DeadlyNightshade::DeadlyNightshade(World* world, OrganismPositon organismPositon)
	:Plant(world, cfg::DEADLY_NIGHTSHADE_STRENGTH, cfg::DEADLY_NIGHTSHADE_INITIATIVE, organismPositon, cfg::DEADLY_NIGHTSHADE_SYMBOL)
{
}

DeadlyNightshade::~DeadlyNightshade()
{
}

void DeadlyNightshade::handleCollision(Organism*)
{
}

