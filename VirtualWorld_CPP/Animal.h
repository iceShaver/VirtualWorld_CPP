#pragma once
#include "Organism.h"

class Animal : public Organism
{
public:
	void act() override;
	Animal(World* world, unsigned short strength, unsigned short initiative, OrganismPositon organismPositon, const char symbol);
	~Animal();
protected:
	OrganismPositon getRandomNeighbourPlace() const;
private:
	void moveTo(OrganismPositon position);
};

