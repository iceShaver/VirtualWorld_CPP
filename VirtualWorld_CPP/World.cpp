#include "World.h"
#include "Console.h"
#include "Program.h"
#include <iostream>
#include "Human.h"

World::World(string name, uint8_t x, uint8_t y, WindowPosition areaPos, WindowPosition reporterPos)
: name(name), reporter(new Reporter), areaPos(areaPos), reporterPos(reporterPos), width(x), height(y), overallTime(0), currentSessionTime(0)
{
	organismsArea = new Organism*[width*height];
	for (int i = 0; i < width*height; ++i)
		organismsArea[i] = nullptr;
	pushOrganism(new Human(this, { 0,0 }), { 0,0 });
	pushOrganism(new Human(this, { 4,0 }), {4,0});
	pushOrganism(new Human(this, { 0,5 }), { 0,5 });
	pushOrganism(new Human(this, { 4,5 }), { 4,5 });


}

World::~World()
{
	delete reporter;
}

void World::playRound()
{
	//TODO: do backend gaming stuff, game internals
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
	for (int i = 0; i < width*height; ++i)
	{
		if (organismsArea[i]) {
			Console::setCursorPos((i%width)+areaPos.x, (i / width)+areaPos.y);
			cout << *organismsArea[i];
		}

	}
}

void World::drawReporter()
{

}

void World::pushOrganism(Organism*organism, OrganismPositon organismPositon)
{
	organismsArea[organismPositon.y*width + organismPositon.x] = organism;
}

Organism* World::pullOrganism(OrganismPositon organismPositon)
{
	Organism*organism = organismsArea[organismPositon.y*width + organismPositon.x];
	organismsArea[organismPositon.y*width + organismPositon.x] = nullptr;
	return organism;
}

void World::deleteOrganism(OrganismPositon organismPositon)
{
	if (organismsArea[organismPositon.y*width + organismPositon.x])
		delete organismsArea[organismPositon.y*width + organismPositon.x];
}

OrganismPositon World::getRandomOrganismPosition() const
{
	OrganismPositon result;
	result.x = Program::getRandomIntNumber(0, width-1);
	result.y = Program::getRandomIntNumber(0, height-1);
	return result;
}

OrganismPositon World::getRandomEmptyOrganismPosition() const
{
	return{ 0,0 };
}

uint8_t World::getWidth()
{
	return width;
}

uint8_t World::getHeight()
{
	return height;
}
