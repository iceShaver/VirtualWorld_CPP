#pragma once
enum Key
{
	EXTENDED_CODE = 0xE0,
	KEY_UP = 0x48, KEY_DOWN = 0x50, KEY_LEFT = 0x4B, KEY_RIGHT = 0x4D, KEY_ENTER = 0x0D, KEY_ESC = 0x1B,
	KEY_HOME = 0x47, KEY_END=0x4F, KEY_PG_UP = 0x49, KEY_PG_DOWN = 0x51, KEY_DELETE=0x53, KEY_SPACE = 0x20,
	KEY_CTRL_S = 0x13
};
class Keyboard
{
public:
	Keyboard();
	~Keyboard();
	static Key getKey();
};

