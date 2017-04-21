#pragma once
#include "Plant.h"

class Guarana : public Plant
{
public:
	Guarana(World* world, OrganismPositon organismPositon);
	~Guarana();
	void handleCollision(Organism*) override;
};

