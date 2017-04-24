#pragma once
#include "Plant.h"

class Guarana : public Plant
{
public:
	Guarana(World* world, OrganismPositon organismPositon);
	~Guarana();
	ResistType resistsAttack(const Organism*otherOrganism)override;
	void sow(const OrganismPositon& organismPosition) override;
};

