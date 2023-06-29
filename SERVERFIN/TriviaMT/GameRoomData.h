#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string>


struct GameRoomData
{
	std::string _status;
	std::string _admin;
	std::string _name;

	int _maxPlayerCount;
	int _questionCount;
	int _questionTime;
};