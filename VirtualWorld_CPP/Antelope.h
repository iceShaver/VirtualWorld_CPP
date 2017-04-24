#pragma once
#include "Animal.h"

class Antelope : public Animal
{
public:
	Antelope(World* world, OrganismPositon organismPositon);
	~Antelope();
	ResistType resistsAttack(const Organism* otherOrganism) override;

	void spawn(const OrganismPositon& organismPosition) override;
	void act() override;
};

