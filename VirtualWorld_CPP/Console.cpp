#include "Console.h"
#include "Config.h"
#include <iostream>
HANDLE Console::consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
short Console::width = cfg::SCREEN_WIDTH;
short Console::height = cfg::SCREEN_HEIGHT;
Console::Console()
{
}


Console::~Console()
{
}

void Console::setCursorPos(short x, short y)
{
	SetConsoleCursorPosition(consoleHandle, { x,y });
}

void Console::clear()
{
	system("cls");
	drawFrame();
}

void Console::drawFrame()
{
	for (int i = 0; i < width; ++i)
	{
		setCursorPos(i, 0);
		putchar(cfg::FRAME_ASCII_CODE);
		setCursorPos(i, height - 1);
		putchar(cfg::FRAME_ASCII_CODE);
	}
	for (int i = 0; i < height; ++i)
	{
		setCursorPos(0, i);
		putchar(cfg::FRAME_ASCII_CODE);
		setCursorPos(width, i);
		putchar(cfg::FRAME_ASCII_CODE);
	}
}

short Console::getWidth()
{
	return width;
}

short Console::getHeight()
{
	return height;
}

void Console::setTextAttributes(WORD wAttributes)
{
	SetConsoleTextAttribute(consoleHandle, wAttributes);
}

void Console::refresh()
{
	setCursorPos(0, 0);
	std::cout.sync_with_stdio(false);
	std::cout << buffer.str();
	buffer.str("");
}

WindowPosition Console::drawWindow(short width, short height)
{
	height++;
	short x = (getWidth() / 2) - (width / 2);
	short y = (getHeight() / 2) - (height / 2);
	setCursorPos(x, y);
	putchar(cfg::FRAME_CORNER_LT);
	setCursorPos(x + width, y);
	putchar(cfg::FRAME_CORNER_RT);
	setCursorPos(x, y + height);
	putchar(cfg::FRAME_CORNER_LB);
	setCursorPos(x + width, y + height);
	putchar(cfg::FRAME_CORNER_RB);
	for (int i = x + 1; i < width + x; ++i)
	{
		setCursorPos(i, y);
		putchar(cfg::FRAME_HORIZONTAL);
		setCursorPos(i, y + height);
		putchar(cfg::FRAME_HORIZONTAL);
	}
	for (int i = y + 1; i < y + height; ++i)
	{
		setCursorPos(x, i);
		putchar(cfg::FRAME_VERTICAL);
		setCursorPos(x + width, i);
		putchar(cfg::FRAME_VERTICAL);
	}
	return { x + 1, y + 1, width };

}

void Console::init()
{
	CONSOLE_CURSOR_INFO cursorInfo;
	COORD coord = { width, height };
	GetConsoleCursorInfo(consoleHandle, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleScreenBufferSize(consoleHandle, coord);
	SetConsoleDisplayMode(consoleHandle, CONSOLE_FULLSCREEN_MODE, &coord);
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);
	setTextAttributes(15);

}
