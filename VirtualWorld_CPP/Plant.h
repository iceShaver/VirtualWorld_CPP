#pragma once
#include "Organism.h"

class Plant : public Organism
{
public:
	void act() override;
	Plant(World* world, unsigned short strength, unsigned short initiative, OrganismPositon organismPositon, const char symbol);
	~Plant();
};

