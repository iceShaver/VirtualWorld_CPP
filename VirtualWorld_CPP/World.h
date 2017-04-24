#pragma once
#include <string>
#include <list>
#include "Console.h"
#include "Reporter.h"
#include "Organism.h"
#include "CyberSheep.h"
#include "Dandelion.h"
#include "DeadlyNightshade.h"
#include "Fox.h"
#include "Grass.h"
#include "Guarana.h"
#include "HeracleumSosnowskyi.h"
#include "Human.h"
#include "Turtle.h"
#include "Wolf.h"
#include <queue>
#include <boost/heap/priority_queue.hpp>
#include <set>
class Program;
class Sheep;
class Antelope;
using namespace std;
class Organism;
//struct OrganismPosition;
class Reporter;
class World
{
public:
	explicit World(string name, uint8_t x, uint8_t y, WindowPosition areaPos,
		WindowPosition reporterPos);

	~World();
	void playRound();
	uint8_t getWidth() const;
	uint8_t getHeight() const;
	void drawArea();
	void drawReporter() const;
	void pushOrganism(Organism*);
	void deleteOrganism(OrganismPositon);
	void deleteOrganism(Organism*);
	Organism* pullOrganism(OrganismPositon);
	Organism*peekOrganism(OrganismPositon) const;
	void moveOrganism(const OrganismPositon& src, const OrganismPositon& dest);
	void newMessage(string message,const Organism*organism = nullptr,
		const Organism*otherOrganism =nullptr) const;

	bool checkIfPlaceIsValidAndEmpty(short x, short y) const;
	bool checkIfPlaceIsValid(short x, short y) const;
	void handleRoundInput() const;
	Human::MovementDirection getHumanMoveDirection() const;
	uint32_t getRoundNumber() const;
private:
	OrganismPositon  getRandomOrganismPosition() const;
	OrganismPositon getRandomEmptyOrganismPosition()const;
	string name;
	uint16_t width, height,totalFields;
	uint32_t overallTime, currentSessionTime, roundCounter;
	vector<vector<Organism*>> *organismsArea;
	Reporter * reporter;
	WindowPosition areaPos, reporterPos;
	multiset<Organism*,Organism::Comparator> priorityQueue;
	multiset<Organism*, Organism::Comparator>::iterator newIterator;
	Human*human;
	friend Organism;
	friend Human;
	friend Program;
};

