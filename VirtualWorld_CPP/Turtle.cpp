#include "Turtle.h"
#include "Config.h"
#include "Program.h"


Turtle::Turtle(World* world, OrganismPositon organismPositon)
	:Animal(world, cfg::TURTLE_STRENGTH, cfg::TURTLE_INITIATIVE,
		organismPositon, cfg::TURTLE_SYMBOL, "Zolw")
{
}

Turtle::~Turtle()
{
}


void Turtle::act()
{
	if (Program::getProbability(0.25)) {
		OrganismPositon* newOrganismPositon = getRandomNeighbourPosition();
		if (!newOrganismPositon) return;
		Organism*neigbourOrganism = world->peekOrganism(*newOrganismPositon);
		if (neigbourOrganism)
			handleCollision(neigbourOrganism);
		else
			moveTo(newOrganismPositon);
		delete newOrganismPositon;
	}
}

Organism::ResistType Turtle::resistsAttack(const Organism* otherOrganism)
{
	if (otherOrganism->getStrength() < cfg::TURTLE_RESIST_MAX_STRENGTH)
		return moveToPreviousPlace;
	return surrender;
}

void Turtle::spawn(const OrganismPositon& organismPosition)
{
	world->pushOrganism(new Turtle(world, organismPosition));

}
