#pragma once
#include "Animal.h"

class Sheep : public Animal
{
public:
	Sheep(World* world, OrganismPositon organismPositon);
	~Sheep();
	void handleCollision(Organism*) override;
};

