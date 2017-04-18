#include "Console.h"
#include "Program.h"
#include "Config.h"
#include <iostream>
#include <string>
int main(int argc, char* argv[])
{
	
	Console::init();
	Program::init();
	Program::displayMenu();
	//for (int i = 0; i < 50; ++i)
	//{
	//	for (int j = 0; j < 10; ++j)
	//	{
	//		Console::buffer << std::string(20, '*') << std::endl;
	//	}
	//	Console::refresh();
	//}

	getchar();
	return 0;
}
