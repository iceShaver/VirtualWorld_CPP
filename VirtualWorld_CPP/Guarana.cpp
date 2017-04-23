#include "Guarana.h"
#include "Config.h"


Guarana::Guarana(World* world, OrganismPositon organismPositon)
	:Plant(world, cfg::GUARANA_STRENGTH, cfg::GUARANA_INITIATIVE, organismPositon, cfg::GUARANA_SYMBOL, "Guarana")
{
}

Guarana::~Guarana()
{
}

void Guarana::handleCollision(Organism*otherOrganism)
{
	Plant::handleCollision(otherOrganism);
}

