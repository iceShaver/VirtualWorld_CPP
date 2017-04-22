#include "Antelope.h"
#include "Config.h"
#include "World.h"

Antelope::Antelope(World* world, OrganismPositon organismPositon)
	:Animal(world, cfg::ANTELOPE_STRENGTH, cfg::ANTELOPE_INITIATIVE, organismPositon, cfg::ANTELOPE_SYMBOL)
{

}

Antelope::~Antelope()
{
}

void Antelope::handleCollision(Organism* organism)
{

}

void Antelope::act()
{

}

