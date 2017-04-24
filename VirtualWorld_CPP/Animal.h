#pragma once
#include "Organism.h"

class Animal : public Organism
{
public:
	virtual void act() override;
	Animal(World* world, unsigned short strength, unsigned short initiative, OrganismPositon organismPositon, const char symbol, std::string name);
	~Animal();
	virtual void spawn(const OrganismPositon&organismPosition)=0;
	void handleCollision(Organism *) override;
protected:
	void moveTo(OrganismPositon * position);
private:
};

