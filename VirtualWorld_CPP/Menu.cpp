#include "Menu.h"
#include <list>
#include "Config.h"
#include "Screen.h"
#include <iostream>
#include <sstream>
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
	x = (Screen::getWidth() / 2) - (width / 2);
	y = (Screen::getHeight() / 2) - (height / 2);
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

void Menu::performAction()
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

void Menu::handleInput()
{
	int c = 0;
	short menuPosition = choice;
	while (true)
	{
		print();
		c = getch();
		if (c == KEY_ESC) Program::close();
		else if (c == KEY_ENTER) performAction();
		else if(c==0xE0)
		switch ((c = getch())) {
		case KEY_UP:
			//cout << "UP";
			menuPosition--;
			break;
		case KEY_DOWN:
			//cout << "DOWN";
			menuPosition++;
			break;
		case KEY_ENTER:
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

void Menu::handle()
{
	Screen::clear();
	handleInput();
}

void Menu::print()
{
	Screen::setCursorPos(x, y);
	putchar(cfg::FRAME_CORNER_LT);
	Screen::setCursorPos(x + width, y);
	putchar(cfg::FRAME_CORNER_RT);
	Screen::setCursorPos(x, y + height);
	putchar(cfg::FRAME_CORNER_LB);
	Screen::setCursorPos(x + width, y + height);
	putchar(cfg::FRAME_CORNER_RB);
	for (int i = x + 1; i < cfg::MENU_WIDTH + x; ++i)
	{
		Screen::setCursorPos(i, y);
		putchar(cfg::FRAME_HORIZONTAL);
		Screen::setCursorPos(i, y + cfg::MENU_HEIGHT);
		putchar(cfg::FRAME_HORIZONTAL);
	}
	for (int i = y + 1; i < y + height; ++i)
	{
		Screen::setCursorPos(x, i);
		putchar(cfg::FRAME_VERTICAL);
		Screen::setCursorPos(x + width, i);
		putchar(cfg::FRAME_VERTICAL);
	}

	short i = 1;
	for (auto position : *positions)
	{
		Screen::setCursorPos(x + ((width / 2) - (position->name.length() / 2)), y + i);
		if (position->function == choice)
			Screen::setTextAttributes(10);
		std::cout << position->name;

		Screen::setTextAttributes(15);
		i++;
	}


}