#pragma once
#include "Plant.h"

class HeracleumSosnowskyi : public Plant
{
public:
	HeracleumSosnowskyi(World* world, OrganismPositon organismPositon);
	~HeracleumSosnowskyi();
	void act()override;
	ResistType resistsAttack(const Organism*otherOrganism)override;
	void sow(const OrganismPositon& organismPosition) override;
};

