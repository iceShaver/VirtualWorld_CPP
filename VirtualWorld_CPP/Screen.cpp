#include "Screen.h"
#include "Config.h"
HANDLE Screen::consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
short Screen::width = cfg::SCREEN_WIDTH;
short Screen::height = cfg::SCREEN_HEIGHT;
Screen::Screen()
{
}


Screen::~Screen()
{
}

void Screen::setCursorPos(short x, short y)
{
	SetConsoleCursorPosition(consoleHandle, { x,y });
}

void Screen::clear()
{
	system("cls");
	drawFrame();
}

void Screen::drawFrame()
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

short Screen::getWidth()
{
	return width;
}

short Screen::getHeight()
{
	return height;
}

void Screen::setTextAttributes(WORD wAttributes)
{
	SetConsoleTextAttribute(consoleHandle, wAttributes);
}

void Screen::init()
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
