#include "Antelope.h"
#include "Config.h"
#include "World.h"

Antelope::Antelope(World* world, OrganismPositon organismPositon)
	:Animal(world, cfg::ANTELOPE_STRENGTH, cfg::ANTELOPE_INITIATIVE, organismPositon, cfg::ANTELOPE_SYMBOL, "Antylopa")
{

}

Antelope::~Antelope()
{
}

void Antelope::handleCollision(Organism* otherOrganism)
{
	Animal::handleCollision(otherOrganism);
}

void Antelope::act()
{
	OrganismPositon* newOrganismPositon = getRandomNeighbourPosition(2);
	if (!newOrganismPositon) return;
	Organism*neigbourOrganism = world->peekOrganism(*newOrganismPositon);
	if (neigbourOrganism)
		handleCollision(neigbourOrganism);
	else {
		moveTo(newOrganismPositon);
	}
	delete newOrganismPositon;
}

