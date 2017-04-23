#include "Animal.h"
#include "World.h"
#include <iostream>

/**
 * \brief Looks for place around and moves to it;
 *  not found->no action;
 *  organism on dest place->call handleCollision();
 */
void Animal::act()
{
	OrganismPositon* newOrganismPositon = getRandomNeighbourPosition();
	if (!newOrganismPositon) return;
	Organism*neigbourOrganism = world->peekOrganism(*newOrganismPositon);
	if (neigbourOrganism)
		handleCollision(neigbourOrganism);
	else
		moveTo(newOrganismPositon);
	delete newOrganismPositon;
}

Animal::Animal(World* world, unsigned short strength, unsigned short initiative, OrganismPositon organismPositon, const char symbol, string name)
	:Organism(world, strength, initiative, organismPositon, symbol, name)
{}

Animal::~Animal()
{
}

void Animal::handleCollision(Organism* otherOrganism)
{
	OrganismPositon* newOrganismPositon = new OrganismPositon{otherOrganism->getOrganismXPos(), otherOrganism->getOrganismYPos()};
	world->newMessage("* ", this, otherOrganism);
	ResistType result = otherOrganism->resistsAttack(this);
	if(result == kill)
	{
		world->newMessage("< ", this, otherOrganism);
		world->deleteOrganism(this);
	}else if(result == surrender)
	{
		world->newMessage("> ", this, otherOrganism);
		world->deleteOrganism(otherOrganism);
		moveTo(newOrganismPositon);
	}else if(result==moveToPreviousPlace)
	{
		world->newMessage("zostaje odepchniety przez ", this, otherOrganism);
	}else if(result==escape)
	{
		world->newMessage("wyploszyl ", this, otherOrganism);
		moveTo(newOrganismPositon);
	}
	delete newOrganismPositon;
}


void Animal::moveTo(OrganismPositon * position)
{
	if (position != nullptr && world->peekOrganism(*position) == nullptr) {
		world->newMessage("-> " + (string)*position, this);
		world->moveOrganism(this->position, *position);
		this->position.x = position->x;
		this->position.y = position->y;
	}
}
