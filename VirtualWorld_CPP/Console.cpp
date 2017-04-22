#include "Console.h"
#include "Config.h"
#include <iostream>
#include <wincon.h>
HANDLE Console::consoleHandle = NULL;
HANDLE Console::bufferHandle = NULL;
uint8_t Console::width = cfg::SCREEN_WIDTH;
uint8_t Console::height = cfg::SCREEN_HEIGHT;
uint8_t Console::internalWidth = width - 2;
uint8_t Console::internalHeight = height - 3;
Console::Console()
{
}

Console::~Console()
{
}

void Console::setCursorPos(uint8_t x, uint8_t y)
{
	SetConsoleCursorPosition(consoleHandle, { x,y });
}

void Console::setCursorPos(WindowPosition winPos)
{
	SetConsoleCursorPosition(consoleHandle, { winPos.x,winPos.y });
}

COORD Console::getCursorPos()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(consoleHandle, &csbi);
	return csbi.dwCursorPosition;
}

void Console::newLine(uint8_t xPos)
{
	COORD position = getCursorPos();
	position.Y++;
	position.X = xPos;
	setCursorPos({ (uint8_t)position.X, (uint8_t)position.Y });
}

void Console::clear()
{
	cls(consoleHandle);
	drawFrame();
}

void Console::drawFrame()
{
	for (int i = 0; i < width; ++i)
	{
		setCursorPos(i, 0);
		putchar(cfg::MAIN_FRAME_ASCII_CODE);
		setCursorPos(i, height - 1);
		putchar(cfg::MAIN_FRAME_ASCII_CODE);
	}
	for (int i = 0; i < height; ++i)
	{
		setCursorPos(0, i);
		putchar(cfg::MAIN_FRAME_ASCII_CODE);
		setCursorPos(width, i);
		putchar(cfg::MAIN_FRAME_ASCII_CODE);
	}
}

uint8_t Console::getWidth()
{
	return width;
}

uint8_t Console::getHeight()
{
	return height;
}

void Console::setTextAttributes(WORD wAttributes)
{
	SetConsoleTextAttribute(consoleHandle, wAttributes);
}

void Console::refresh()
{

	bufferCopy(consoleHandle, bufferHandle, width, height);
}

WindowPosition Console::drawWindow(uint8_t width, uint8_t height)
{
	clear();
	height++;
	uint8_t x = (getWidth() / 2) - (width / 2);
	uint8_t y = (getHeight() / 2) - (height / 2);
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
	return { (uint8_t)(x + 1), (uint8_t)(y + 1), width, height };

}

WindowPosition Console::drawWindow(WindowComposition windowComposition, uint8_t widthP, uint8_t heightP)
{
	//TODO: fix returned WindowPosition values
	auto windowPosition = getWindowPosition(windowComposition, widthP, heightP);
	windowPosition.x--;
	windowPosition.y--;
	uint8_t width = windowPosition.width;
	uint8_t height = windowPosition.height;
	uint8_t x = windowPosition.x;
	uint8_t y = windowPosition.y;
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
	return { uint8_t(x + 1), uint8_t(y + 1), width, height };
}

WindowPosition Console::getWindowPosition(WindowComposition windowComposition, uint8_t widthP, uint8_t heightP)
{
	uint8_t width, height, x, y;
	//clear();
	switch (windowComposition)
	{
	case left:
		if (widthP && heightP) {
			height = heightP + 1;
			width = widthP + 1;
		}
		else
		{
			height = internalHeight;
			width = (internalWidth / 2) - 2;
		}
		x = 1;
		y = 1;
		break;
	case right:
		height = internalHeight;
		width = internalWidth / 2;
		x = internalWidth / 2;
		y = 1;
		break;
	case top:
		height = internalHeight / 2;
		width = internalWidth;
		x = 1;
		y = 1;
		break;
	case bottom:
		height = (internalHeight / 2) - 1;
		width = internalWidth;
		x = 1;
		y = (internalHeight / 2) + 2;
		break;
	case top_left:
		height = internalHeight / 2;
		width = (internalWidth / 2) - 2;
		x = 1;
		y = 1;
		break;
	case top_right:
		height = internalHeight / 2;
		width = internalWidth / 2;
		x = internalWidth / 2;
		y = 1;
		break;
	case bottom_left:
		height = (internalHeight / 2) - 1;
		width = (internalWidth / 2) - 2;
		x = 1;
		y = (internalHeight / 2) + 2;
		break;
	case bottom_right:
		height = (internalHeight / 2) - 1;
		width = internalWidth / 2;
		x = internalWidth / 2;
		y = (internalHeight / 2) + 2;
		break;
	case full:
		height = internalHeight;
		width = internalWidth;
		x = 1;
		y = 1;
		break;
	case center:
		if (widthP && heightP)
		{
			width = widthP;
			height = heightP;
		}
		else
		{
			width = 20;
			height = 10;
		}
		x = (getWidth() / 2) - (width / 2);
		y = (getHeight() / 2) - (height / 2);
		break;
	default:
		x = 0;
		y = 0;
		height = 0;
		width = 0;
		break;
	}
	return{ uint8_t(x + 1), uint8_t(y + 1), width, height };
}


void Console::bufferCopy(const HANDLE& src, HANDLE& dest, size_t width, size_t height)
{
	COORD bufferSize;
	bufferSize.X = (SHORT)width;
	bufferSize.Y = (SHORT)height;
	SMALL_RECT srcRect;
	srcRect.Left = 0;
	srcRect.Top = 0;
	srcRect.Right = (SHORT)width - 1;
	srcRect.Bottom = (SHORT)height -1;
	CHAR_INFO * charInfoArray = new CHAR_INFO[width*height];
	ReadConsoleOutput(src, charInfoArray, bufferSize, { 0,0 }, &srcRect);
	WriteConsoleOutput(dest, charInfoArray, bufferSize, { 0,0 }, &srcRect);
	delete[] charInfoArray;
}

void Console::cls(HANDLE handle)
{
	COORD coordScreen = { 0, 0 };    // home for the cursor 
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;

	// Get the number of character cells in the current buffer. 

	if (!GetConsoleScreenBufferInfo(handle, &csbi))
	{
		return;
	}

	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

	// Fill the entire screen with blanks.

	if (!FillConsoleOutputCharacter(handle,        // Handle to console screen buffer 
		(TCHAR) ' ',     // Character to write to the buffer
		dwConSize,       // Number of cells to write 
		coordScreen,     // Coordinates of first cell 
		&cCharsWritten))// Receive number of characters written
	{
		return;
	}

	// Get the current text attribute.

	if (!GetConsoleScreenBufferInfo(handle, &csbi))
	{
		return;
	}

	// Set the buffer's attributes accordingly.

	if (!FillConsoleOutputAttribute(handle,         // Handle to console screen buffer 
		csbi.wAttributes, // Character attributes to use
		dwConSize,        // Number of cells to set attribute 
		coordScreen,      // Coordinates of first cell 
		&cCharsWritten)) // Receive number of characters written
	{
		return;
	}

	// Put the cursor at its home coordinates.

	SetConsoleCursorPosition(handle, coordScreen);
}

void Console::init()
{
	std::cout.sync_with_stdio(false);
	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	bufferHandle = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	CONSOLE_CURSOR_INFO cursorInfo;
	COORD coord = { width, height };
	GetConsoleCursorInfo(consoleHandle, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleScreenBufferSize(consoleHandle, coord);
	SetConsoleDisplayMode(consoleHandle, CONSOLE_FULLSCREEN_MODE, &coord);
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);
	SetConsoleScreenBufferSize(bufferHandle, coord);
	SetConsoleDisplayMode(bufferHandle, CONSOLE_FULLSCREEN_MODE, &coord);
	SetConsoleCursorInfo(bufferHandle, &cursorInfo);
	setTextAttributes(15);
	//TODO: Fix console double buffering
	//SetConsoleActiveScreenBuffer(bufferHandle);

}
