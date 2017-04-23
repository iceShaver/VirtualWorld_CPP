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
	: name(name), reporter(new Reporter(this, reporterPos)), areaPos(areaPos), reporterPos(reporterPos), width(x), height(y), overallTime(0), currentSessionTime(0), totalFields(x*y)
{
	organismsArea = new Organism*[totalFields];
	for (int i = 0; i < totalFields; ++i)
		organismsArea[i] = nullptr;
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

	//for (int i = 0; i < totalFields*cfg::ORGANISM_FULFILLMENT_RATIO*cfg::ORGANISM_FULFILLMENT_RATIO; ++i)
	//{
	//	OrganismType organism = (OrganismType)Program::getRandomIntNumber(0, 11);
	//	switch (organism)
	//	{
	//	case antelope:
	//		pushOrganism(new Antelope(this, getRandomEmptyOrganismPosition()));
	//		break;
	//	case cyberSheep:
	//		pushOrganism(new CyberSheep(this, getRandomEmptyOrganismPosition()));
	//		break;
	//	case dandelion:
	//		pushOrganism(new Dandelion(this, getRandomEmptyOrganismPosition()));
	//		break;
	//	case deadlyNightshade:
	//		pushOrganism(new DeadlyNightshade(this, getRandomEmptyOrganismPosition()));
	//		break;
	//	case fox:
	//		pushOrganism(new Fox(this, getRandomEmptyOrganismPosition()));
	//		break;
	//	case grass:
	//		pushOrganism(new Grass(this, getRandomEmptyOrganismPosition()));
	//		break;
	//	case guarana:
	//		pushOrganism(new Guarana(this, getRandomEmptyOrganismPosition()));
	//		break;
	//	case heracleumSosnowskyi:
	//		pushOrganism(new HeracleumSosnowskyi(this, getRandomEmptyOrganismPosition()));
	//		break;
	//	case human:
	//		//pushOrganism(new Human(this, getRandomEmptyOrganismPosition()));
	//		break;
	//	case sheep:
	//		pushOrganism(new Sheep(this, getRandomEmptyOrganismPosition()));
	//		break;
	//	case turtle:
	//		pushOrganism(new Turtle(this, getRandomEmptyOrganismPosition()));
	//		break;
	//	case wolf:
	//		pushOrganism(new Wolf(this, getRandomEmptyOrganismPosition()));
	//		break;
	//	default:;
	//	}
	//}


}

World::~World()
{
	delete reporter;
}

void World::playRound()
{
	for (auto organism : priorityQueue)
	{
		organism->increaseAge();
		organism->act();
	}
	//for (int i = 0; i < totalFields; ++i)
	//{
	//	if (organismsArea[i]) {
	//		organismsArea[i]->increaseAge();
	//		organismsArea[i]->act();
	//	}
	//}
}

void World::drawArea()
{
	//version for list
	/*for (auto organism : organisms)
	{
		Console::setCursorPos(organism->getOrganismXPos()+areaPos.x, organism->getOrganismYPos()+areaPos.y);
		cout << *organism;
	}*/

	//version for array
	for (int i = 0; i < totalFields; ++i)
	{
		if (organismsArea[i]) {
			Console::setCursorPos((i%width) + areaPos.x, (i / width) + areaPos.y);
			cout << *organismsArea[i];
		}

	}
	if (cfg::DEBUG) {
		//Console::setCursorPos(Console::getWidth()-10, 4);
		int x = Console::getWidth() - 10;
		/*for (int i = 0; i < totalFields; ++i)
		{
			if (organismsArea[i]) {
				cout << *organismsArea[i];
				Console::nextLine(x);
			}

		}
		x += 5;*/
		Console::setCursorPos(x, 3);
		for (auto organism : priorityQueue)
		{
			cout << *organism << " " << organism->getInitiative() << " " << organism->getAge();
			Console::nextLine(x);
		}
	}
}

void World::drawReporter()
{
	reporter->printMessages();
}

void World::pushOrganism(Organism*organism)
{
	organismsArea[organism->getOrganismYPos()*width + organism->getOrganismXPos()] = organism;
	priorityQueue.insert(organism);
}

Organism* World::pullOrganism(OrganismPositon organismPositon)
{
	size_t index = organismPositon.y*width + organismPositon.x;
	Organism*organism = organismsArea[index];
	organismsArea[index] = nullptr;
	std::multiset<Organism*, Organism::Comparator>::iterator delElem = priorityQueue.find(organism);
	priorityQueue.erase(delElem);
	return organism;
}
void World::moveOrganism(const OrganismPositon& src, const OrganismPositon& dest)
{
	size_t srcIndex = src.y*width + src.x;
	size_t destIndex = dest.y*width + dest.x;
	if (organismsArea[destIndex] == nullptr) {
		organismsArea[destIndex] = organismsArea[srcIndex];
		organismsArea[srcIndex] = nullptr;
	}
}

void World::newMessage(string message, const Organism* organism, const Organism*otherOrganism) const
{
	reporter->newMessage(message, organism, otherOrganism);
}

bool World::checkIfPlaceIsValidAndEmpty(short x, short y) const
{
	if (x < 0 || y < 0 || x >= areaPos.width-1 || y >= areaPos.height-1) return false;
	if (peekOrganism({ x, y })) return false;
	return true;
}

bool World::checkIfPlaceIsValid(short x, short y) const
{
	if (x < 0 || y < 0 || x >= areaPos.width-1 || y >= areaPos.height-1) return false;
	return true;
}

void World::handleRoundInput()
{
	bool flag = true;
	while (flag)
	{
		//if (Keyboard::getKey() == KEY_ENTER) break;
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
		case KEY_ESC: Program::close();	break;
		default:;
		}
		Program::drawGameInterface();
	}
	//while (Keyboard::getKey() != KEY_ENTER);

}

void World::setHumanMoveDirection(Human::MovementDirection movementDirection)
{

}

Human::MovementDirection World::getHumanMoveDirection()
{
	return human->getMovementDirection();
}


void World::deleteOrganism(OrganismPositon organismPositon)
{
	int index = organismPositon.y*width + organismPositon.x;
	if (organismsArea[index]) {
		std::multiset<Organism*, Organism::Comparator>::iterator delElem = priorityQueue.find(organismsArea[index]);
		priorityQueue.erase(delElem);
		delete organismsArea[index];
		organismsArea[index] = nullptr;
	}
}

void World::deleteOrganism(Organism*organism)
{
	std::multiset<Organism*, Organism::Comparator>::iterator delElem = priorityQueue.find(organism);
	priorityQueue.erase(delElem);
	size_t index = (*delElem)->getOrganismYPos()*width + (*delElem)->getOrganismXPos();
	if (organismsArea[index])
	{
		delete organismsArea[index];
		organismsArea[index] = nullptr;
	}
}


Organism* World::peekOrganism(OrganismPositon organismPositon) const
{
	return organismsArea[organismPositon.y*width + organismPositon.x];
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


uint8_t World::getWidth()
{
	return width;
}

uint8_t World::getHeight()
{
	return height;
}

