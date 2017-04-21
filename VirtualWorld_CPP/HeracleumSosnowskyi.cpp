#include "HeracleumSosnowskyi.h"
#include "Config.h"


HeracleumSosnowskyi::HeracleumSosnowskyi(World* world, OrganismPositon organismPositon)
	:Plant(world, cfg::HARACLEUM_SOSNOWSKYI_STRENGTH, cfg::HERACLEUM_SOSNOWSKYI_INITIATIVE, organismPositon, cfg::HERACLEUM_SOSNOWSKYI_SYMBOL)
{
}

HeracleumSosnowskyi::~HeracleumSosnowskyi()
{
}

void HeracleumSosnowskyi::handleCollision(Organism*)
{
}

