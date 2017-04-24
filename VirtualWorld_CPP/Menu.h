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
	void performSelectedAction() const;
	void handle();
private:
	void draw() const;
	std::list<Position*>*positions;
	short x, y, width, height;
	Function choice;
};

