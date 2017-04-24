#include "Guarana.h"
#include "Config.h"
#include "World.h"

Guarana::Guarana(World* world, OrganismPositon organismPositon)
	:Plant(world, cfg::GUARANA_STRENGTH, cfg::GUARANA_INITIATIVE, organismPositon, cfg::GUARANA_SYMBOL, "Guarana")
{
}

Guarana::~Guarana()
{
}

Organism::ResistType Guarana::resistsAttack(const Organism* otherOrganism)
{
	return increaseStrength;
}

void Guarana::sow(const OrganismPositon& organismPosition)
{
	world->pushOrganism(new Guarana(world, organismPosition));

}

