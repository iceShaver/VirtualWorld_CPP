#include "Animal.h"

void Animal::act()
{
	moveTo(getRandomNeighbourPlace());
}

Animal::Animal(World* world, unsigned short strength, unsigned short initiative, OrganismPositon organismPositon, const char symbol)
	:Organism(world, strength, initiative, organismPositon, symbol)
{}

Animal::~Animal()
{
}

OrganismPositon Animal::getRandomNeighbourPlace() const
{
	//TODO: compute random neighbour place
	OrganismPositon organismPositon;
	return organismPositon;
}

void Animal::moveTo(OrganismPositon position)
{
	this->position = position;
}
