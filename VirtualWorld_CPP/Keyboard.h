#pragma once
enum Key
{
	EXTENDED_CODE= 0xE0,
	KEY_UP=0x48, KEY_DOWN=0x50, KEY_LEFT=0x4B, KEY_RIGHT=0x4D, KEY_ENTER=0x0D, KEY_ESC=0x1B
};
class Keyboard
{
public:
	Keyboard();
	~Keyboard();
	static Key getKey();
};

