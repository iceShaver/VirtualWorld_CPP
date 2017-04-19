#pragma once
#include <string>
#include <list>
#include "Organism.h"
#include "Console.h"
#include "Reporter.h"
using namespace std;
class Organism;
class Reporter;
class World
{
public:
	
	explicit World(string name, short x, short y, WindowPosition areaPos, WindowPosition reporterPos);
	~World();
	void playRound();
	uint8_t getRandomNumber(uint8_t floor, uint8_t ceiling);
	void randomize();
	uint8_t getWidth();
	uint8_t getHeight();
private:
	void drawArea(const WindowPosition& window_position);
	string name;
	uint8_t width, height;
	uint32_t overallTime, currentSessionTime;
	list<Organism*> organisms;
	Reporter * reporter;
	WindowPosition areaPos, reporterPos;
};

