#pragma once
#include "Animal.h"

class Antelope : public Animal
{
public:
	Antelope(World* world, OrganismPositon organismPositon);
	~Antelope();
	void handleCollision(Organism*) override;
	ResistType resistsAttack(const Organism* otherOrganism) override;
	void act() override;
};

