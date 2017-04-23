#include "Program.h"
#include "Config.h"
#include <boost/filesystem.hpp>
#include "Console.h"
#include <iostream>
#include <ctime>
#include "Keyboard.h"
using namespace std;
Program::Status Program::status;
World * Program::world;
Menu * Program::userMenu;
void Program::init()
{
	srand(time(nullptr));
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
		cout << "Podaj wymiary swiata szerokosc, wysokosc rozdzielone spacja: ";
		Console::refresh();
		cin >> x >> y;
		world = new World(name, x, y,
			Console::getWindowPosition(WindowComposition::left, x, y),
			Console::getWindowPosition(WindowComposition::bottom_right)
			);
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
	Console::drawWindow(WindowComposition::left, world->getWidth(), world->getHeight());
	Console::drawWindow(WindowComposition::bottom_right);
	//TODO: draw results of game, reporter and info
	drawInstruction(Console::drawWindow(WindowComposition::top_right));
	world->drawArea();
	world->drawReporter();
	Console::refresh();
}

void Program::playTheGame()
{
	world->playRound();
	drawGameInterface();
	//fflush(stdin);
	world->handleRoundInput();
}

bool Program::getProbability(double probability)
{
	double random = ((double)rand() / (RAND_MAX));
	if (random <= probability) return true;
	return false;
}

int Program::getRandomIntNumber(int floor, int ceiling)
{
	return rand()%ceiling+floor;
}

void Program::drawInstruction(WindowPosition windowPosition)
{
	uint8_t x = windowPosition.x;
	void(*newLine)(uint8_t) = Console::nextLine;
	Console::setCursorPos(windowPosition);
	cout << "Instrukcja gry";
	newLine(x);
	newLine(x);
	cout << "1. Oznaczenia organizmow:";
	newLine(x+=3);
	cout << "A - antylopa";
	newLine(x);
	cout << "C - cyber-owca";
	newLine(x);
	cout << "M - mlecz";
	newLine(x);
	cout << "J - wilcza jagoda";
	newLine(x);
	cout << "L - lis";
	newLine(x);
	cout << "T - trawa";
	newLine(x);
	cout << "G - guarana";
	newLine(x);
	cout << "B - barszcz sosnowskiego";
	newLine(x);
	cout << "H - czlowiek";
	newLine(x);
	cout << "O - owca";
	newLine(x);
	cout << "Z - zolw";
	newLine(x);
	cout << "W - wilk";
	newLine(x-=3);
	newLine(x);
	cout << "2. Sterowanie:";
	newLine(x+=3);
	cout << "[ENTER] - wykonaj ture";
	newLine(x);
	cout << "[STRZALKI] - okresl kierunek ruchu czlowieka";
	newLine(x);
	cout << "Obecny kierunek ruchu czlowieka: " << world->getHumanMoveDirection();


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