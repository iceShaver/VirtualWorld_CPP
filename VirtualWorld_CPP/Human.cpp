#include "Human.h"
#include "Config.h"


Human::Human(World* world, OrganismPositon organismPositon)
	:Animal(world, cfg::HUMAN_STRENGTH, cfg::HUMAN_INITIATIVE, organismPositon, cfg::HUMAN_SYMBOL, "Czlowiek")
{
}

Human::~Human()
{
}

void Human::handleCollision(Organism*)
{
}

