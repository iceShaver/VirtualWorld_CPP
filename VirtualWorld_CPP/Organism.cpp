#include "Organism.h"


Organism::Organism()
{
}

Organism::Organism(World& world, unsigned short strength, unsigned short priority, unsigned short x, unsigned short y) 
: world(&world), strength(strength),priority(priority), x(x), y(y)
{
}

Organism::~Organism()
{
}
