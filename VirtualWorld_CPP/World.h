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
	
	explicit World(string name, short x, short y);
	~World();
	void playRound();
private:
	void drawArea(const WindowPosition& window_position);
	string name;
	short x, y;
	uint32_t overallTime, currentSessionTime;
	list<Organism*> organisms;
	Reporter * reporter;
};

