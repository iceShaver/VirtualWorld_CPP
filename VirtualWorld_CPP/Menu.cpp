#include "Menu.h"
#include <list>
#include "Config.h"
#include "Console.h"
#include <iostream>
#include <conio.h>
#include "Keyboard.h"
#include "Program.h"
using namespace std;
Menu::Menu()
{
	positions = new std::list<Position*>;
	positions->push_back(new Position{ "Nowa gra", newGame });
	positions->push_back(new Position{ "Wczytaj gre", loadGame });
	positions->push_back(new Position{ "Wyjscie", exit });
	width = cfg::MENU_WIDTH;
	height = cfg::MENU_HEIGHT;
	x = (Console::getWidth() / 2) - (width / 2);
	y = (Console::getHeight() / 2) - (height / 2);
	choice = newGame;
}


Menu::~Menu()
{
	for (auto position : *positions)
	{
		delete position;
	}
	delete positions;
}

void Menu::performSelectedAction()
{
	switch (choice)
	{
	case newGame:
		Program::newGame();
		break;
	case loadGame:
		Program::loadGame();
		break;
	case exit:
		Program::close();
		break;
	default:
		break;
	}
}


void Menu::handle()
{
	Console::clear();
	short menuPosition = choice;
	while (true)
	{
		draw();
		switch(Keyboard::getKey())
		{
		case KEY_UP:
			//cout << "UP";
			menuPosition--;
			break;
		case KEY_DOWN:
			//cout << "DOWN";
			menuPosition++;
			break;
		case KEY_ENTER:
			performSelectedAction();
			break;
		case KEY_ESC:
			Program::close();
			break;
		default:
			break;
		}
		if (choice != menuPosition)
		{
			int mod = menuPosition % (int)positions->size();
			menuPosition = (mod < 0 ? positions->size() + mod : mod);
			choice = (Function)menuPosition;
		}
		//while (_kbhit()) _getch();

	}
}

void Menu::draw() const
{
	WindowPosition winPos = Console::drawWindow(width, height);
	short i = 1;
	for (auto position : *positions)
	{
		Console::setCursorPos(winPos.x + ((width / 2) - (position->name.length() / 2)), winPos.y + i);
		if (position->function == choice)
			Console::setTextAttributes(10);
		std::cout << position->name;
		Console::setTextAttributes(15);
		i++;
	}


}
