#pragma once
#include "Animal.h"

class CyberSheep : public Animal
{
public:
	CyberSheep(World* world, OrganismPositon organismPositon);
	~CyberSheep();

	void spawn(const OrganismPositon& organismPosition) override;
};

