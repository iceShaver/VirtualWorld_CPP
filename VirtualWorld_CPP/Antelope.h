#pragma once
#include "Animal.h"

class Antelope : public Animal
{
public:
	Antelope(World* world, OrganismPositon organismPositon);
	~Antelope();
	void handleCollision(Organism*) override;
};

