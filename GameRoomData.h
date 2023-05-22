#pragma once

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