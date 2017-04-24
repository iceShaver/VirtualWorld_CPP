#pragma once
#include "Organism.h"

class Plant : public Organism
{
public:
	void act() override;
	virtual void sow(const OrganismPositon&organismPosition) = 0;
	virtual void handleCollision(Organism*)override;
	Plant(World* world, unsigned short strength, unsigned short initiative,
		OrganismPositon organismPositon, const char symbol, std::string name);
	~Plant();
};

