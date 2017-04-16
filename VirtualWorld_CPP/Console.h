#pragma once
#include <Windows.h>
#include <sstream>
struct WindowPosition
{
	short x, y, width, height;
};
class Console
{
public:
	Console();
	~Console();
	static void init();
	static void setCursorPos(short x, short y);
	static void clear();
	static void drawFrame();
	static short getWidth();
	static short getHeight();
	static void setTextAttributes(WORD wAttributes);
	static void refresh();
	static WindowPosition drawWindow(short width, short height);
	static std::stringstream buffer;
private:
	static HANDLE consoleHandle;
	static short width, height;
	static void bufferCopy(const HANDLE & src, HANDLE & dest, size_t width, size_t height);
	static void cls(HANDLE handle);
};

