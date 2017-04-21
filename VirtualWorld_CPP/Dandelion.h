#pragma once
#include "Plant.h"

class Dandelion : public Plant
{
public:
	Dandelion(World* world, OrganismPositon organismPositon);
	~Dandelion();
	void handleCollision(Organism*) override;
};

