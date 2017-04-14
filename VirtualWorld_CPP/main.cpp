#include "Screen.h"
#include "Program.h"
#include "Config.h"
#include <iostream>

int main(int argc, char* argv[])
{
	
	Screen::init();
	Program::init();
	Program::displayMenu();

	getchar();
	return 0;
}
