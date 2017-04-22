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
}

Animal::Animal(World* world, unsigned short strength, unsigned short initiative, OrganismPositon organismPositon, const char symbol)
	:Organism(world, strength, initiative, organismPositon, symbol)
{}

Animal::~Animal()
{
}



void Animal::moveTo(OrganismPositon * position)
{
	if (position != nullptr && world->peekOrganism(*position) == nullptr) {
		world->moveOrganism(this->position, *position);
		this->position.x = position->x;
		this->position.y = position->y;
		delete position;
	}
}
