#include "Plant.h"
#include "Program.h"
#include "Config.h"


void Plant::act()
{
	if (Program::getProbability(cfg::PLANT_SOW_PROBABILITY))
	{
		OrganismPositon * op = getRandomNeighbourPosition(1, onlyEmpty);
		if (op) {
			OrganismPositon orgPos = { op->x, op->y };
			sow(orgPos);
			delete op;
		}

	}
}

void Plant::handleCollision(Organism*)
{

}

Plant::Plant(World* world, unsigned short strength, unsigned short initiative, OrganismPositon organismPositon, const char symbol, std::string name)
	:Organism(world, strength, initiative, organismPositon, symbol, name)
{
}

Plant::~Plant()
{
}
