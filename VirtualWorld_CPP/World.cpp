#include "World.h"
#include "Console.h"
#include "Program.h"
#include <iostream>
#include "Human.h"
#include "Antelope.h"
#include "CyberSheep.h"
#include "Dandelion.h"
#include "DeadlyNightshade.h"
#include "Fox.h"
#include "Grass.h"
#include "Guarana.h"
#include "HeracleumSosnowskyi.h"
#include "Sheep.h"
#include "Turtle.h"
#include "Wolf.h"
#include "Config.h"
#include <set>
#include "Keyboard.h"
//#include "Organism.h"

World::World(string name, uint8_t x, uint8_t y, WindowPosition areaPos, WindowPosition reporterPos)
	: name(name), reporter(new Reporter(this, reporterPos)), areaPos(areaPos), reporterPos(reporterPos),
	width(x), height(y), overallTime(0), currentSessionTime(0), totalFields(x*y), newIterator(priorityQueue.end()),
	roundCounter(0)
{

	organismsArea = new vector<vector<Organism*>>(x + 10, vector<Organism*>(y + 10));
	for (int i = 0; i < x; ++i)
	{
		for (int j = 0; j < y; ++j)
		{
			(*organismsArea)[x][y] = nullptr;
		}
	}
	human = new Human(this, getRandomEmptyOrganismPosition());
	pushOrganism(human);

	//Push at least one organism of each type
	for (int i = 0; i < 3; ++i)
	{
		pushOrganism(new Antelope(this, getRandomEmptyOrganismPosition()));
		pushOrganism(new CyberSheep(this, getRandomEmptyOrganismPosition()));
		pushOrganism(new Dandelion(this, getRandomEmptyOrganismPosition()));
		pushOrganism(new DeadlyNightshade(this, getRandomEmptyOrganismPosition()));
		pushOrganism(new Fox(this, getRandomEmptyOrganismPosition()));
		pushOrganism(new Grass(this, getRandomEmptyOrganismPosition()));
		pushOrganism(new Guarana(this, getRandomEmptyOrganismPosition()));
		pushOrganism(new HeracleumSosnowskyi(this, getRandomEmptyOrganismPosition()));
		pushOrganism(new Sheep(this, getRandomEmptyOrganismPosition()));
		pushOrganism(new Turtle(this, getRandomEmptyOrganismPosition()));
		pushOrganism(new Wolf(this, getRandomEmptyOrganismPosition()));
	}


	//Push additional organisms randomly

	for (int i = 0; i < totalFields*cfg::ORGANISM_FULFILLMENT_RATIO*cfg::ORGANISM_FULFILLMENT_RATIO; ++i)
	{
		OrganismType organism = static_cast<OrganismType>(Program::getRandomIntNumber(0, 11));
		switch (organism)
		{
		case antelope:
			pushOrganism(new Antelope(this, getRandomEmptyOrganismPosition()));
			break;
		case cyberSheep:
			pushOrganism(new CyberSheep(this, getRandomEmptyOrganismPosition()));
			break;
		case dandelion:
			pushOrganism(new Dandelion(this, getRandomEmptyOrganismPosition()));
			break;
		case deadlyNightshade:
			pushOrganism(new DeadlyNightshade(this, getRandomEmptyOrganismPosition()));
			break;
		case fox:
			pushOrganism(new Fox(this, getRandomEmptyOrganismPosition()));
			break;
		case grass:
			pushOrganism(new Grass(this, getRandomEmptyOrganismPosition()));
			break;
		case guarana:
			pushOrganism(new Guarana(this, getRandomEmptyOrganismPosition()));
			break;
		case heracleumSosnowskyi:
			pushOrganism(new HeracleumSosnowskyi(this, getRandomEmptyOrganismPosition()));
			break;
		case OrganismType::human:
			//pushOrganism(new Human(this, getRandomEmptyOrganismPosition()));
			break;
		case sheep:
			pushOrganism(new Sheep(this, getRandomEmptyOrganismPosition()));
			break;
		case turtle:
			pushOrganism(new Turtle(this, getRandomEmptyOrganismPosition()));
			break;
		case wolf:
			pushOrganism(new Wolf(this, getRandomEmptyOrganismPosition()));
			break;
		default:;
		}
	}


}

World::~World()
{
	delete reporter;
}

void World::playRound()
{
	roundCounter++;
	vector<Organism*> organismsToDelete;
	for (auto organism : priorityQueue)
		organism->increaseAge();
	for (multiset<Organism*, Organism::Comparator>::iterator it = priorityQueue.begin(); it != priorityQueue.end(); )
	{
		(*it)->act();
		if (newIterator != priorityQueue.end()) {
			it = newIterator;
			newIterator = priorityQueue.end();
		}
		else ++it;

	}
}

void World::drawArea()
{
	for (int i = 0; i < width; ++i)
	{
		for (int j = 0; j < height; ++j)
		{
			if ((*organismsArea)[i][j]) {
				Console::setCursorPos(i + areaPos.x, j + areaPos.y);
				cout << *(*organismsArea)[i][j];
			}
		}


	}
	if (cfg::DEBUG) {
		int x = Console::getWidth() - 10;

		Console::setCursorPos(x, 3);
		for (auto organism : priorityQueue)
		{
			cout << *organism << " " << organism->getInitiative() 
			<< " " << organism->getAge();
			Console::nextLine(x);
		}
	}
}


void World::drawReporter() const
{
	reporter->printMessages();
}

void World::pushOrganism(Organism*organism)
{
	(*organismsArea)[organism->getOrganismXPos()][organism->getOrganismYPos()] = organism;
	priorityQueue.insert(organism);
}

Organism* World::pullOrganism(OrganismPositon organismPositon)
{
	size_t index = organismPositon.y*width + organismPositon.x;
	Organism*organism = (*organismsArea)[organismPositon.x][organismPositon.y];
	(*organismsArea)[organismPositon.x][organismPositon.y] = nullptr;
	multiset<Organism*, Organism::Comparator>::iterator delElem = priorityQueue.find(organism);
	priorityQueue.erase(delElem);
	return organism;
}
void World::moveOrganism(const OrganismPositon& src, const OrganismPositon& dest)
{
	size_t srcIndex = src.y*width + src.x;
	size_t destIndex = dest.y*width + dest.x;
	if ((*organismsArea)[dest.x][dest.y] == nullptr) {
		(*organismsArea)[dest.x][dest.y] = (*organismsArea)[src.x][src.y];
		(*organismsArea)[src.x][src.y] = nullptr;
	}
}

void World::newMessage(string message, const Organism* organism, const Organism*otherOrganism) const
{
	reporter->newMessage(message, organism, otherOrganism);
}

bool World::checkIfPlaceIsValidAndEmpty(short x, short y) const
{
	if (x < 0 || y < 0 || x >= areaPos.width - 1 || y >= areaPos.height - 1) return false;
	if (peekOrganism({ x, y })) return false;
	return true;
}

bool World::checkIfPlaceIsValid(short x, short y) const
{
	if (x < 0 || y < 0 || x >= areaPos.width - 1 || y >= areaPos.height - 1) return false;
	return true;
}

void World::handleRoundInput() const
{
	bool flag = true;
	while (flag)
	{
		if (human)
			switch (Keyboard::getKey())
			{
				//case EXTENDED_CODE: break;
			case KEY_UP: human->setMovementDirection(Human::up); break;
			case KEY_DOWN: human->setMovementDirection(Human::down); break;
			case KEY_LEFT: human->setMovementDirection(Human::left); break;
			case KEY_RIGHT: human->setMovementDirection(Human::right); break;
			case KEY_ENTER: flag = false; break;
			case KEY_HOME: human->setMovementDirection(Human::upLeft); break;
			case KEY_END: human->setMovementDirection(Human::downLeft); break;
			case KEY_PG_UP: human->setMovementDirection(Human::upRight); break;
			case KEY_PG_DOWN: human->setMovementDirection(Human::downRight); break;
			case KEY_DELETE: human->setMovementDirection(Human::undefined); break;
			case KEY_SPACE: human->activateAlzursShield(); break;
			case KEY_CTRL_S: Program::saveGame(); break;
			case KEY_ESC: Program::close();	break;
			default:;
			}
		else
			switch (Keyboard::getKey())
			{
			case KEY_ENTER: flag = false; break;
			case KEY_CTRL_S: Program::saveGame(); break;
			case KEY_ESC: Program::close();	break;
			default:;
			}
		Program::drawGameInterface();
	}

}



Human::MovementDirection World::getHumanMoveDirection() const
{
	if (human)
		return human->getMovementDirection();
	return Human::undefined;
}


void World::deleteOrganism(OrganismPositon organismPositon)
{
	if ((*organismsArea)[organismPositon.x][organismPositon.y]) {
		std::multiset<Organism*, Organism::Comparator>::iterator delElem = std::find(priorityQueue.begin(), priorityQueue.end(), peekOrganism(organismPositon));
		newIterator = priorityQueue.erase(delElem);
		delete (*organismsArea)[organismPositon.x][organismPositon.y];
		(*organismsArea)[organismPositon.x][organismPositon.y] = nullptr;
	}

}

void World::deleteOrganism(Organism*organism)
{
	short x = organism->getOrganismXPos();
	short y = organism->getOrganismYPos();
	std::multiset<Organism*, Organism::Comparator>::iterator delElem =
		std::find(priorityQueue.begin(), priorityQueue.end(), organism);

	if (delElem == priorityQueue.end()) return;
	newIterator = next(delElem);
	priorityQueue.erase(delElem);
	delete organism;
	if ((*organismsArea)[x][y])
		(*organismsArea)[x][y] = nullptr;
	
}


Organism* World::peekOrganism(OrganismPositon organismPositon) const
{
	return (*organismsArea)[organismPositon.x][organismPositon.y];
}

OrganismPositon World::getRandomOrganismPosition() const
{
	OrganismPositon result;
	result.x = Program::getRandomIntNumber(0, width - 1);
	result.y = Program::getRandomIntNumber(0, height - 1);
	return result;
}

OrganismPositon World::getRandomEmptyOrganismPosition() const
{
	OrganismPositon op;
	while (true)
	{
		op = getRandomOrganismPosition();
		if (!peekOrganism(op))
			return op;
	}
}


uint8_t World::getWidth() const
{
	return width;
}

uint8_t World::getHeight() const
{
	return height;
}


uint32_t World::getRoundNumber() const
{
	return roundCounter;
}
