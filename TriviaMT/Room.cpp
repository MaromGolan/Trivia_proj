#include "Room.h"


using std::string;



Room::Room(const GameRoomData& roomData)
{
	_roomData = roomData;
	_playerSet.insert(roomData._admin);
}

Room::Room(const GameRoomData& roomData, User u)
{
	_roomData = roomData;
	this->users.push_back(u);
}



void Room::addUser(const string& username)
{
	_playerSet.insert(username);
}

void Room::addUser(User u)
{
	this->users.push_back(u);
}



void Room::removeUser(const string& username)
{
	_playerSet.erase(username);
}


std::set<string> Room::getAllUsers() const
{
	return _playerSet;
}


std::string Room::isActive() const
{
	return _roomData._status;
}


GameRoomData Room::getData() const
{
	return _roomData;
}

void Room::activate()
{
	_roomData._status = "playing";
}

void Room::close()
{
	_roomData._status = "closed";
}
