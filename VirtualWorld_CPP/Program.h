#pragma once
#include "Menu.h"
#include "World.h"
#include <string>
#include <vector>

class Program
{
public:
	enum Status { menu, running, paused, userRound, exit };
	static void init();
	static void handle();
	static void newGame();
	static void loadGame();
	static void saveGame();
	static void handleEvent();
	static Status getStatus();
	static void setStatus(Status status);
	static void displayMenu();
	static void close();
	static void drawGameInterface();
	static void playTheGame();
	static bool getProbability(double probability);
	static int getRandomIntNumber(int floor, int ceiling);
	static void drawInstruction(WindowPosition);
private:
	static std::vector<std::string> * getFilesList();
	static bool doesEntryExist(std::string fileName);
	static World * world;
	static Status status;
	static Menu * userMenu;
};

