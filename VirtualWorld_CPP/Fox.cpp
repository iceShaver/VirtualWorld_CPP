#include "Fox.h"
#include "Config.h"
#include "World.h"

Fox::Fox(World* world, OrganismPositon organismPositon)
	:Animal(world, cfg::FOX_STRENGTH, cfg::FOX_INITIATIVE, organismPositon, cfg::FOX_SYMBOL, "Lis")
{
}

Fox::~Fox()
{
}


void Fox::act()
{
	OrganismPositon* newOrganismPositon = getRandomNeighbourPosition(1,emptyOrWithWeakOrganism);
	if (!newOrganismPositon) return;
	Organism*neigbourOrganism = world->peekOrganism(*newOrganismPositon);
	if (neigbourOrganism)
		handleCollision(neigbourOrganism);
	else
		moveTo(newOrganismPositon);
	delete newOrganismPositon;
}

void Fox::spawn(const OrganismPositon& organismPosition)
{
	world->pushOrganism(new Fox(world, organismPosition));

}

