#pragma once
#include <Windows.h>
class Screen
{
public:
	Screen();
	~Screen();
	static void init();
	static void setCursorPos(short x, short y);
	static void clear();
	static void drawFrame();
	static short getWidth();
	static short getHeight();
	static void setTextAttributes(WORD wAttributes);
private:
	static HANDLE consoleHandle;
	static short width, height;
};

