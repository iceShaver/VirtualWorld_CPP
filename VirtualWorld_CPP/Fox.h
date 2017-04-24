#pragma once
#include "Animal.h"

class Fox : public Animal
{
public:
	Fox(World* world, OrganismPositon organismPositon);
	~Fox();
	void act()override;
	void spawn(const OrganismPositon& organismPosition) override;
};

