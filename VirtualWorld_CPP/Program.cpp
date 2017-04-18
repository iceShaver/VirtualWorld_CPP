#include "Program.h"
#include "Config.h"
#include <boost/filesystem.hpp>
#include "Console.h"
#include <iostream>
using namespace std;
Program::Status Program::status;
World * Program::world;
Menu * Program::userMenu;
void Program::init()
{
	status = menu;
	world = nullptr;
	userMenu = new Menu();
}

void Program::handle()
{
}

void Program::newGame()
{
	bool nameUsed = false;
	while (true)
	{
		Console::clear();
		WindowPosition winPos = Console::drawWindow(55, 2);
		Console::setCursorPos(winPos);
		if (nameUsed) {
			cout << "Podana nazwa zostala juz wykorzystana. Uzyj innej";
			Console::setCursorPos(winPos.x, winPos.y + 1);
		}
		cout << "Podaj nazwe nowej gry: ";
		Console::refresh();
		string name;
		short x, y;
		cin >> name;
		if (Program::doesEntryExist(name))
		{
			nameUsed = true;
			continue;
		}
		Console::setCursorPos(Console::drawWindow(50, 2));
		cout << "Podaj wymiary swiata x, y rozdzielone spacja: ";
		Console::refresh();
		cin >> x >> y;
		world = new World(name, x, y);
		Program::setStatus(running);
		break;
	}

}

void Program::loadGame()
{
}

void Program::saveGame()
{
}

void Program::handleEvent()
{
}

Program::Status Program::getStatus()
{
	return status;
}

void Program::setStatus(Status status)
{
	Program::status = status;
}

void Program::displayMenu()
{
	userMenu->handle();
}

void Program::close()
{
	delete userMenu;
	::exit(0);
}

void Program::drawGameInterface()
{
	Console::clear();
	WindowPosition areaPos = Console::drawWindow(WindowComposition::left);
	WindowPosition reporterPos = Console::drawWindow(WindowComposition::top_right);
	WindowPosition infoPos = Console::drawWindow(WindowComposition::bottom_right);

	//TODO: draw results of game, reporter and info


	Console::refresh();
	getchar();
}

void Program::playTheGame()
{
	world->playRound();
	drawGameInterface();
}

vector<string> * Program::getFilesList()
{
	auto result = new vector<string>;
	for (boost::filesystem::directory_iterator iterator(cfg::SAVE_DIR);
		iterator != boost::filesystem::directory_iterator();
		++iterator)
	{
		result->push_back(iterator->path().stem().string());
	}
	return result;
}

bool Program::doesEntryExist(string fileName)
{
	return boost::filesystem::exists(fileName + "." + cfg::SAVE_EXT);
}