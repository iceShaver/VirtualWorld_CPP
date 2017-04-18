#pragma once
#include "World.h"
class World;
class Organism
{
public:
	Organism();
	explicit Organism(World&world, unsigned short strength, unsigned short priority, unsigned short x, unsigned short y);
	virtual ~Organism();
	virtual void Act()=0;
	virtual void HandleCollision()=0;
	virtual void Draw()=0;
	virtual operator char()=0;
private:
	unsigned short strength;
	unsigned short priority;
	unsigned short x, y;
	World * world;
};

