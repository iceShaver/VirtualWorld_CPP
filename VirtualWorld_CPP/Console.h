#pragma once
#include <Windows.h>
#include <sstream>
struct WindowPosition
{
	uint8_t x, y, width, height;
};
enum WindowComposition {
	left, right, top, bottom, top_left, top_right, bottom_left, bottom_right, center, full
};
class Console
{
public:
	Console();
	~Console();
	static void init();
	static void setCursorPos(uint8_t x, uint8_t y);
	static void setCursorPos(WindowPosition winPos);
	static COORD getCursorPos();
	static void nextLine(uint8_t xPos);
	static void prevLine(uint8_t xPos);
	static void clear();
	static void drawFrame();
	static uint8_t getWidth();
	static uint8_t getHeight();
	static void setTextAttributes(WORD wAttributes);
	static void refresh();
	static WindowPosition drawWindow(uint8_t width, uint8_t height);
	static WindowPosition drawWindow(WindowComposition windowComposition, uint8_t widthP = 0, uint8_t heightP = 0);
	static WindowPosition getWindowPosition(WindowComposition windowComposition, uint8_t widthP = 0, uint8_t heightP = 0);
	static HANDLE consoleHandle;
	static HANDLE bufferHandle;
private:
	static uint8_t width, height, internalWidth, internalHeight;
	static void bufferCopy(const HANDLE & src, HANDLE & dest, size_t width, size_t height);
	static void cls(HANDLE handle);
};

