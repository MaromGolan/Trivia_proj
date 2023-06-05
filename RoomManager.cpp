#include "RoomManager.h"
#include "RoomException.h"
#include "GameRoom.h"



//a function to add a room to the room manager;
void RoomManager::createRoom(const GameRoomData& roomData)
{
	if (roomData._name == "")
	{
		throw RoomException("Room name can't be empty.");
	}

	_rooms[roomData._name] = Room(roomData);
}


//a function to remove a room from the room manager;
void RoomManager::closeRoom(const std::string& roomName)
{
	if (!_rooms.erase(roomName))
	{
		throw RoomException("The room doesn't exist");
	}

}


//a function to join a room;
void RoomManager::joinRoom(const JoinRoomRequest& req)
{

	if (_rooms.find(req._roomName) == _rooms.end())
	{
		throw RoomException("The room doesn't exist");
	}

	
	auto maxPlayers = _rooms[req._roomName].getData()._maxPlayerCount;
	
	if (maxPlayers && maxPlayers == _rooms[req._roomName].getAllUsers().size())
	{
		throw RoomException("This room is full.");
	}
	
	_rooms[req._roomName].addUser(req._user);

}


//a function to leave a room;
void RoomManager::leaveRoom(const LeaveRoom& req)
{

	//if they are equal, we will not have to do anything;
	if (_rooms.find(req._roomName) != _rooms.end())
	{
		_rooms[req._roomName].removeUser(req._user);
	}

}


//a function to obtain the players in the room via a string;
std::set<std::string> RoomManager::getPlayersInRoom(const std::string& roomName)
{
	if (_rooms.find(roomName) == _rooms.end())
	{
		throw RoomException("The room doesn't exists");
	}

	return _rooms[roomName].getAllUsers();

}



//a function to obtain the state of a room;
GameRoomData RoomManager::getRoomData(const std::string& roomName)
{
	if (_rooms.find(roomName) == _rooms.end())
	{
		throw RoomException("The room doesn't exist");
	}
	
	return _rooms[roomName].getData();

}


//a function to obtain the rooms;
std::unordered_map<std::string, Room> RoomManager::GetRooms()
{
	return _rooms;
}


//a function to activate a room;
void RoomManager::activateRoom(const std::string& roomName)
{
	if (_rooms.find(roomName) == _rooms.end())
	{
		throw RoomException("The room doesn't exists");
	}

	_rooms[roomName].activate();

}