#pragma once
#include "Plant.h"

class Dandelion : public Plant
{
public:
	Dandelion(World* world, OrganismPositon organismPositon);
	~Dandelion();
	void act()override;
	void sow(const OrganismPositon& organismPosition) override;
};

