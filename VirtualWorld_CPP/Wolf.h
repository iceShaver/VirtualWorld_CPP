#pragma once
#include "Animal.h"

class Wolf : public Animal
{
public:
	Wolf(World* world, OrganismPositon organismPositon);
	~Wolf();
	void handleCollision(Organism*) override;
};

