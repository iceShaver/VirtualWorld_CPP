#pragma once
#include "Animal.h"

class Turtle : public Animal
{
public:
	Turtle(World* world, OrganismPositon organismPositon);
	~Turtle();
	void act()override;
	ResistType resistsAttack(const Organism* otherOrganism) override;

	void spawn(const OrganismPositon& organismPosition) override;
};

