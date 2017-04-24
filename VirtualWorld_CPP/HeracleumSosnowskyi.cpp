#include "HeracleumSosnowskyi.h"
#include "Config.h"
#include "World.h"

HeracleumSosnowskyi::HeracleumSosnowskyi(World* world, OrganismPositon organismPositon)
	:Plant(world, cfg::HARACLEUM_SOSNOWSKYI_STRENGTH, cfg::HERACLEUM_SOSNOWSKYI_INITIATIVE, organismPositon, cfg::HERACLEUM_SOSNOWSKYI_SYMBOL, "Barszcz sosnowskiego")
{
}

HeracleumSosnowskyi::~HeracleumSosnowskyi()
{
}


void HeracleumSosnowskyi::act()
{
	//TODO: Exception for cyber-sheep and Plants
	Plant::act();
	vector<OrganismPositon> organismPositons = getAllNeigbourPosition();
	for (OrganismPositon organismPositon : organismPositons)
	{
		Organism*organism = world->peekOrganism(organismPositon);
		if (organism) {
			if (dynamic_cast<Animal*>(organism) && !dynamic_cast<CyberSheep*>(organism)) {
				world->newMessage("zabija ", this, world->peekOrganism(organismPositon));
				world->deleteOrganism(organismPositon);
			}
		}
	}

}

Organism::ResistType HeracleumSosnowskyi::resistsAttack(const Organism* otherOrganism)
{
	if (dynamic_cast<const CyberSheep*>(otherOrganism))
		return surrender;
	return kill;
}

void HeracleumSosnowskyi::sow(const OrganismPositon& organismPosition)
{
	world->pushOrganism(new HeracleumSosnowskyi(world, organismPosition));

}

