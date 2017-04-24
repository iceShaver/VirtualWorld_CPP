#include "Animal.h"
#include "World.h"
#include <iostream>
#include "Config.h"
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

Animal::Animal(World* world, unsigned short strength, unsigned short initiative,
	OrganismPositon organismPositon, const char symbol, string name)
	:Organism(world, strength, initiative, organismPositon, symbol, name)
{}

Animal::~Animal()
{
}

void Animal::handleCollision(Organism* otherOrganism)
{
	OrganismPositon* newOrganismPositon = 
		new OrganismPositon{otherOrganism->getOrganismXPos(), otherOrganism->getOrganismYPos()};
	world->newMessage("* ", this, otherOrganism);
	if(getName()==otherOrganism->getName())
	{
		
		//TODO:DONE random pos for new animal
		OrganismPositon*tmp = getRandomNeighbourPosition(1, onlyEmpty);
		if (!tmp)return; //abort
		OrganismPositon organismPositon{tmp->x, tmp->y};
		delete tmp;
		world->newMessage("nowe zwierze", this);
		spawn(organismPositon);
		return;
	}
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
	}else if(result == increaseStrength)
	{
		strength += cfg::GUARANA_STRENGTH_INCREASE_VALUE;
		stringstream message;
		message << "sila rosnie do " << strength << " ";
		world->newMessage("> ", this, otherOrganism);
		world->deleteOrganism(otherOrganism);
		world->newMessage(message.str(), this);
		moveTo(newOrganismPositon);
	}else if(result==moveAroundMe)
	{
		OrganismPositon * newOrganismPos = 
			getRandomNeighbourPosition(1, onlyEmpty, otherOrganism);
		if(newOrganismPos)
		{
			moveTo(newOrganismPos);
			delete newOrganismPos;
		}
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
