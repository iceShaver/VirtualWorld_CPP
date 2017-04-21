#include "Wolf.h"
#include "Config.h"


Wolf::Wolf(World* world, OrganismPositon organismPositon)
	:Animal(world, cfg::WOLF_STRENGTH, cfg::WOLF_INITIATIVE, organismPositon, cfg::WOLF_SYMBOL)
{
}

Wolf::~Wolf()
{
}

void Wolf::handleCollision(Organism*)
{
}

