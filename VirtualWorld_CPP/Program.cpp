#include "Program.h"
#include "Config.h"
#include <boost/filesystem.hpp>
#include "Console.h"
Program::Status Program::status;
World * Program::world;
Menu * Program::userMenu;
void Program::init()
{
	status = menu;
	world = nullptr;
	userMenu = new Menu();
}

void Program::handle()
{
}

void Program::newGame()
{
	Console::clear();
	WindowPosition winPos = Console::drawWindow(50, 2);
	
}

void Program::loadGame()
{
}

void Program::saveGame()
{
}

void Program::handleEvent()
{
}

Program::Status Program::getStatus()
{
	return status;
}

void Program::setStatus(Status status)
{
	Program::status = status;
}

void Program::displayMenu()
{
	userMenu->handle();
}

void Program::close()
{
	delete userMenu;
	::exit(0);
}

std::vector<std::string> * Program::getFilesList()
{
	auto result = new std::vector<std::string>;
	for (boost::filesystem::directory_iterator iterator(cfg::SAVE_DIR);
		iterator != boost::filesystem::directory_iterator();
		++iterator)
	{
		result->push_back(iterator->path().stem().string());
	}
	return result;
}

bool Program::doesEntryExist(std::string fileName)
{
	return boost::filesystem::exists(fileName + "." + cfg::SAVE_EXT);
}