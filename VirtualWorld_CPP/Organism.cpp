#include "Organism.h"
#include "World.h"



Organism::Organism(World * world, unsigned short strength, unsigned short initiative, OrganismPositon organismPositon, const char symbol)
	:world(world), strength(strength), initiative(initiative), position(organismPositon), symbol(symbol)
{

}


Organism::~Organism()
{
}

Organism::operator char()
{
	return symbol;
}

OrganismPositon Organism::getOrganismPosition() const
{
	return position;
}

uint8_t Organism::getOrganismXPos() const
{
	return position.x;
}

uint8_t Organism::getOrganismYPos() const
{
	return  position.y;
}

