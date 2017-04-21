#include "Turtle.h"
#include "Config.h"


Turtle::Turtle(World* world, OrganismPositon organismPositon)
	:Animal(world, cfg::TURTLE_STRENGTH, cfg::TURTLE_INITIATIVE, organismPositon, cfg::TURTLE_SYMBOL)
{
}

Turtle::~Turtle()
{
}

void Turtle::handleCollision(Organism*)
{
}
