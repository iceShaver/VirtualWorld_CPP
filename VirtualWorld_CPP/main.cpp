#include "Console.h"
#include "Program.h"
#include "Config.h"
#include <iostream>
#include <string>
#include <cstdio>
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
	
	return 0;
}
