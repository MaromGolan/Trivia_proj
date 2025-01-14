#pragma once

#include "Room.h"
#include "Structs.h"

#include <unordered_map>


class RoomManager
{

public:
	
	void createRoom(const GameRoomData& roomData);
	void closeRoom(const std::string& roomName);
	
	void joinRoom(const JoinRoomRequest&);	
	void leaveRoom(const LeaveRoom& req);

	GameRoomData getRoomData(const std::string& roomName);
	std::set<std::string> getPlayersInRoom(const std::string& name);
	std::unordered_map<std::string, Room> GetRooms();

	void activateRoom(const std::string& roomName);
	static std::unordered_map<std::string, Room> _rooms;


private:

};

