#pragma once
#include "Plant.h"

class DeadlyNightshade : public Plant
{
public:
	DeadlyNightshade(World* world, OrganismPositon organismPositon);
	~DeadlyNightshade();
	ResistType resistsAttack(const Organism*otherOrganism)override;
	void sow(const OrganismPositon& organismPosition) override;
};

