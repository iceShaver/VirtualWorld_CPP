#pragma once
#include "Plant.h"

class DeadlyNightshade : public Plant
{
public:
	DeadlyNightshade(World* world, OrganismPositon organismPositon);
	~DeadlyNightshade();
	void handleCollision(Organism*) override;
};

