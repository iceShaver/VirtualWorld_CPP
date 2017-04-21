#pragma once
#include "Animal.h"

class Human : public Animal
{
public:
	Human(World* world, OrganismPositon organismPositon);
	~Human();
	void handleCollision(Organism*) override;
};

