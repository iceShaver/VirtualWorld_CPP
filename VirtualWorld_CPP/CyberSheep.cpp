#include "CyberSheep.h"
#include "Config.h"
#include "World.h"

CyberSheep::CyberSheep(World* world, OrganismPositon organismPositon)
	:Animal(world, cfg::CYBER_SHEEP_STRENGTH, cfg::CYBER_SHEEP_INITIATIVE,
		organismPositon, cfg::CYBER_SHEEP_SYMBOL, "Cyber-Owca")
{
}

CyberSheep::~CyberSheep()
{
}

void CyberSheep::spawn(const OrganismPositon& organismPosition)
{
	world->pushOrganism(new CyberSheep(world, organismPosition));
}

