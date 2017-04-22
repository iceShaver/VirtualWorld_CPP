#pragma once
#include "Organism.h"

class Animal : public Organism
{
public:
	virtual void act() override;
	Animal(World* world, unsigned short strength, unsigned short initiative, OrganismPositon organismPositon, const char symbol);
	~Animal();
protected:
private:
	void moveTo(OrganismPositon * position);
};

