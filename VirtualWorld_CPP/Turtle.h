#pragma once
#include "Animal.h"

class Turtle : public Animal
{
public:
	Turtle(World* world, OrganismPositon organismPositon);
	~Turtle();
	void handleCollision(Organism*) override;
	void act()override;
	ResistType resistsAttack(const Organism* otherOrganism) override;
};

