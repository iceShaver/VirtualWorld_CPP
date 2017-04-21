#pragma once
#include "Plant.h"

class HeracleumSosnowskyi : public Plant
{
public:
	HeracleumSosnowskyi(World* world, OrganismPositon organismPositon);
	~HeracleumSosnowskyi();
	void handleCollision(Organism*) override;
};

