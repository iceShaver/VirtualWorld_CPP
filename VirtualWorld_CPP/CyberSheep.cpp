#include "CyberSheep.h"
#include "Config.h"


CyberSheep::CyberSheep(World* world, OrganismPositon organismPositon)
	:Animal(world, cfg::CYBER_SHEEP_STRENGTH, cfg::CYBER_SHEEP_INITIATIVE, organismPositon, cfg::CYBER_SHEEP_SYMBOL)
{
}

CyberSheep::~CyberSheep()
{
}

void CyberSheep::handleCollision(Organism*)
{
}

