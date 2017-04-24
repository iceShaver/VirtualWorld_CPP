#pragma once
#include "Organism.h"

class Animal : public Organism
{
public:
	Animal(World* world, unsigned short strength, unsigned short initiative,
		OrganismPositon organismPositon, const char symbol, std::string name);
	~Animal();
	void act() override;
	void handleCollision(Organism *) override;
	virtual void spawn(const OrganismPositon&organismPosition) = 0;
protected:
	void moveTo(OrganismPositon * position);
};

