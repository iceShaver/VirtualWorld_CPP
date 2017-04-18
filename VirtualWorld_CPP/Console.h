#pragma once
#include <Windows.h>
#include <sstream>
struct WindowPosition
{
	short x, y, width, height;
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
	static void setCursorPos(short x, short y);
	static void setCursorPos(WindowPosition winPos);
	static void clear();
	static void drawFrame();
	static short getWidth();
	static short getHeight();
	static void setTextAttributes(WORD wAttributes);
	static void refresh();
	static WindowPosition drawWindow(short width, short height);
	static WindowPosition drawWindow(WindowComposition windowComposition, short widthP = 0, short heightP = 0);
	static HANDLE consoleHandle;
	static HANDLE bufferHandle;
private:
	static short width, height, internalWidth, internalHeight;
	static void bufferCopy(const HANDLE & src, HANDLE & dest, size_t width, size_t height);
	static void cls(HANDLE handle);
};

