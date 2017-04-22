#pragma once
#include <cstdint>
#include <string>
//#include "World.h"
class World;
struct OrganismPositon
{
	uint8_t x, y;
	operator std::string() const;
};
enum OrganismType{antelope,cyberSheep, dandelion, deadlyNightshade, fox, grass, guarana, heracleumSosnowskyi, human, sheep, turtle, wolf};
class Organism
{
public:
	struct Comparator
	{
		bool operator()(const Organism* left, const Organism*right)const;
	};
	explicit Organism(World* world, unsigned short strength, unsigned short initiative, OrganismPositon organismPositon, const char symbol, std::string name);
	virtual ~Organism();
	virtual void act()=0;
	virtual void handleCollision(Organism*)=0;
	virtual operator char();
	//virtual void draw()=0;
	OrganismPositon getOrganismPosition() const;
	OrganismPositon * getRandomNeighbourPosition(uint8_t range = 1, bool mustBeEmpty = false) const;
	uint8_t getOrganismXPos() const;
	uint8_t getOrganismYPos() const;
	virtual void increaseAge();
	uint32_t getAge()const;
	unsigned short getInitiative();
	std::string getName()const;
protected:
	OrganismPositon position;
	const char symbol;
	uint32_t age;
	World * world;
private:
	unsigned short strength;
	unsigned short initiative;
	std::string name;

	//friend Comparator;
};

