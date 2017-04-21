#pragma once
#include <string>
#include <list>
#include "Console.h"
#include "Reporter.h"
#include "Organism.h"
using namespace std;
class Organism;
//struct OrganismPosition;
class Reporter;
class World
{
public:
	explicit World(string name, uint8_t x, uint8_t y, WindowPosition areaPos, WindowPosition reporterPos);
	~World();
	void playRound();
	uint8_t getWidth();
	uint8_t getHeight();
	void drawArea();
	void drawReporter();
	void pushOrganism(Organism*, OrganismPositon);
	Organism* pullOrganism(OrganismPositon);
	void deleteOrganism(OrganismPositon);
private:
	OrganismPositon  getRandomOrganismPosition() const;
	OrganismPositon getRandomEmptyOrganismPosition()const;
	string name;
	uint8_t width, height;
	uint32_t overallTime, currentSessionTime;
	Organism**organismsArea;
	Reporter * reporter;
	WindowPosition areaPos, reporterPos;
	friend Organism;
};

