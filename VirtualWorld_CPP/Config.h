#pragma once
#include <string>

namespace cfg
{
	const std::string SAVE_DIR = ".";
	const std::string SAVE_EXT = "bin";
	const short MENU_HEIGHT = 10;
	const short MENU_WIDTH = 50;
	const short SCREEN_WIDTH = 200;
	const short SCREEN_HEIGHT = 50;

	//frames ascii codes
	const char MAIN_FRAME_ASCII_CODE = (char)219;
	const char FRAME_HORIZONTAL = (char)205;
	const char FRAME_VERTICAL = (char)186;
	const char FRAME_CORNER_LT = (char)201;
	const char FRAME_CORNER_RT = (char)187;
	const char FRAME_CORNER_LB = (char)200;
	const char FRAME_CORNER_RB = (char)188;

	//Organisms symbols
	const char ANTELOPE_SYMBOL = 'A';
	const char CYBER_SHEEP_SYMBOL = 'C';
	const char DANDELION_SYMBOL = 'M';
	const char DEADLY_NIGHTSHADE_SYMBOL = 'J';
	const char FOX_SYMBOL = 'L';
	const char GRASS_SYMBOL = 'T';
	const char GUARANA_SYMBOL = 'G';
	const char HERACLEUM_SOSNOWSKYI_SYMBOL = 'B';
	const char HUMAN_SYMBOL = 'H';
	const char SHEEP_SYMBOL = 'S';
	const char TURTLE_SYMBOL = 'Z';
	const char WOLF_SYMBOL = 'W';

	//Organisms strengths
	const uint8_t ANTELOPE_STRENGTH = 4;
	const uint8_t CYBER_SHEEP_STRENGTH = 11;
	const uint8_t DANDELION_STRENGTH = 0;
	const uint8_t DEADLY_NIGHTSHADE_STRENGTH = 99;
	const uint8_t FOX_STRENGTH = 3;
	const uint8_t GRASS_STRENGTH = 0;
	const uint8_t GUARANA_STRENGTH = 0;
	const uint8_t HARACLEUM_SOSNOWSKYI_STRENGTH = 10;
	const uint8_t HUMAN_STRENGTH = 5;
	const uint8_t SHEEP_STRENGTH = 4;
	const uint8_t TURTLE_STRENGTH = 2;
	const uint8_t WOLF_STRENGTH = 9;

	//Organisms initiatives

	const uint8_t ANTELOPE_INITIATIVE = 4;
	const uint8_t CYBER_SHEEP_INITIATIVE = 4;
	const uint8_t DANDELION_INITIATIVE = 0;
	const uint8_t DEADLY_NIGHTSHADE_INITIATIVE = 0;
	const uint8_t FOX_INITIATIVE = 7;
	const uint8_t GRASS_INITIATIVE = 0;
	const uint8_t GUARANA_INITIATIVE = 0;
	const uint8_t HERACLEUM_SOSNOWSKYI_INITIATIVE = 0;
	const uint8_t HUMAN_INITIATIVE = 4;
	const uint8_t SHEEP_INITIATIVE = 4;
	const uint8_t TURTLE_INITIATIVE = 1;
	const uint8_t WOLF_INITIATIVE = 5;

}
