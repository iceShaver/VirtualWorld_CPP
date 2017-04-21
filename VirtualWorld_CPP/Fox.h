#pragma once
#include "Animal.h"

class Fox : public Animal
{
public:
	Fox(World* world, OrganismPositon organismPositon);
	~Fox();
	void handleCollision(Organism*) override;
};

