#pragma once
#include <cstdint>
//#include "World.h"
class World;
struct OrganismPositon { uint8_t x, y; };
class Organism
{
public:

	explicit Organism(World* world, unsigned short strength, unsigned short initiative, OrganismPositon organismPositon, const char symbol);
	virtual ~Organism();
	virtual void act()=0;
	virtual void handleCollision(Organism*)=0;
	virtual operator char();
	//virtual void draw()=0;
	OrganismPositon getOrganismPosition() const;
	uint8_t getOrganismXPos() const;
	uint8_t getOrganismYPos() const;
protected:
	OrganismPositon position;
	const char symbol;
private:
	unsigned short strength;
	unsigned short initiative;
	World * world;
};

