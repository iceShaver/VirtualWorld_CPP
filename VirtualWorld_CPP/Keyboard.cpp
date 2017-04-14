#include "Keyboard.h"
#include <conio.h>


Keyboard::Keyboard()
{
}


Keyboard::~Keyboard()
{
}

Key Keyboard::getKey()
{
	int key = _getch();
	if (key == EXTENDED_CODE) return (Key)_getch();
	return (Key)key;
}
