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

void Room::removeUser(User u)
{
	std::vector<User> us;
	for(int i = 0; i < this->users.size(); i++)
	{
		if (this->users.at(i).Username != u.Username)
		{
			us.push_back(this->users.at(i));
		}
	}
	this->users = us;
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
