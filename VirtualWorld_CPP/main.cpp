#include "Console.h"
#include "Program.h"
#include "Config.h"
#include <iostream>
#include <string>
int main(int argc, char* argv[])
{
	
	Console::init();
	Program::init();
	while (true)
	{
		switch (Program::getStatus())
		{
		case Program::running:
			Program::playTheGame();
			break;
		case Program::menu:
			Program::displayMenu();
			break;
		case Program::paused:
			break;
		case Program::userRound:
			break;
		case Program::exit:
			Program::close();
			break;
		}
		
	}
	
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
