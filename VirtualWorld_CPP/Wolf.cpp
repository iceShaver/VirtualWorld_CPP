#include "Wolf.h"
#include "Config.h"
#include "World.h"

Wolf::Wolf(World* world, OrganismPositon organismPositon)
	:Animal(world, cfg::WOLF_STRENGTH, cfg::WOLF_INITIATIVE, organismPositon, cfg::WOLF_SYMBOL, "Wilk")
{
}

Wolf::~Wolf()
{
}

void Wolf::spawn(const OrganismPositon& organismPosition)
{
	world->pushOrganism(new Wolf(world, organismPosition));

}

