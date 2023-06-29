#pragma once

#include <set>
#include "Structs.h"
#include "User.h"
#include "GameRoomData.h"
#include <vector>
#include "GameManager.h"
class Room
{

public:
	
	//constructor;
	Room() = default;
	Room(const GameRoomData& roomData);
	Room(const GameRoomData& roomData, User u);

	//methods;
	void addUser(const std::string& username);
	void addUser(User u);

	void removeUser(const std::string& username);
	void removeUser(User u);

	std::set<std::string> getAllUsers() const;
	
	//getters and setters;
	std::string isActive() const;
	GameRoomData getData() const;
	void activate();
	void close();
	std::vector<User> users;
	//std::set<User> users;
	GameManager gm;
private:
	
	GameRoomData _roomData;
	std::set<std::string> _playerSet;
	
};

