#pragma once
#include "Plant.h"

class Grass : public Plant
{
public:
	Grass(World* world, OrganismPositon organismPositon);
	~Grass();
	void sow(const OrganismPositon& organismPosition) override;
};

