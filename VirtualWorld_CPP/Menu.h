#pragma once
#include <list>
#include <string>
class Menu
{
public:
	enum Function { newGame=0, loadGame=1, exit=2 };
	struct Position
	{
		std::string name;
		Function function;
	};
	Menu();
	~Menu();
	void performAction();
	void handleInput();
	void handle();
private:
	void print();
	std::list<Position*>*positions;
	short x, y, width, height;
	Function choice;
};

