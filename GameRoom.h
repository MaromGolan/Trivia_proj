#pragma once

#include <set>
#include "GameRoomData.h"


class Room
{

public:
	
	//constructor;
	Room();
	Room(const GameRoomData& roomData);
	
	//methods;
	void addUser(const std::string& username);
	void removeUser(const std::string& username);
	std::set<std::string> getAllUsers() const;
	
	//getters and setters;
	std::string isActive() const;
	GameRoomData getData() const;
	void activate();
	void close();

private:

	GameRoomData _roomData;
	std::set<std::string> _playerSet;
	
};

