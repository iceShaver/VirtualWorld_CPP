#pragma once
#include "Organism.h"

class Animal : public Organism
{
public:
	virtual void act() override;
	Animal(World* world, unsigned short strength, unsigned short initiative, OrganismPositon organismPositon, const char symbol, std::string name);
	~Animal();
protected:
	void moveTo(OrganismPositon * position);
private:
};

