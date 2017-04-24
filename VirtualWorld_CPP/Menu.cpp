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

void Menu::performSelectedAction() const
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
		Program::setStatus(Program::exit);
		break;
	default:
		break;
	}
}


void Menu::handle()
{
	short menuPosition = choice;
		draw();
		switch(Keyboard::getKey())
		{
		case KEY_UP:
			menuPosition--;
			break;
		case KEY_DOWN:
			menuPosition++;
			break;
		case KEY_ENTER:
			performSelectedAction();
			break;
		case KEY_ESC:
			Program::setStatus(Program::exit);
			break;
		default:
			break;
		}
		if (choice != menuPosition)
		{
			int mod = menuPosition % (int)positions->size();
			menuPosition = (short)(mod < 0 ? positions->size() + mod : mod);
			choice = (Function)menuPosition;
		}

}

void Menu::draw() const
{
	Console::clear();
	WindowPosition winPos = Console::drawWindow(width, height);
	short i = 1;
	for (auto position : *positions)
	{
		Console::setCursorPos((short)(winPos.x + ((width / 2) - (position->name.length() / 2))), winPos.y + i);
		if (position->function == choice)
			Console::setTextAttributes(10);
		std::cout << position->name;
		Console::setTextAttributes(15);
		i++;
	}
	Console::refresh();


}
