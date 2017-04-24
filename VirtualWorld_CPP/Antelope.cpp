#include "Antelope.h"
#include "Config.h"
#include "World.h"
#include "Program.h"

Antelope::Antelope(World* world, OrganismPositon organismPositon)
	:Animal(world, cfg::ANTELOPE_STRENGTH, cfg::ANTELOPE_INITIATIVE,
		organismPositon, cfg::ANTELOPE_SYMBOL, "Antylopa")
{

}

Antelope::~Antelope()
{
}


Organism::ResistType Antelope::resistsAttack(const Organism* otherOrganism)
{
	if (Program::getProbability(0.5))
	{
		OrganismPositon* newOrganismPositon = getRandomNeighbourPosition(2, onlyEmpty);
		if (newOrganismPositon) {
			moveTo(newOrganismPositon);
			delete newOrganismPositon;
			return escape;
		}
		
	} 
	return Animal::resistsAttack(otherOrganism);
}

void Antelope::spawn(const OrganismPositon& organismPosition)
{
	world->pushOrganism(new Antelope(world, organismPosition));
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

