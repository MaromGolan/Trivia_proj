#pragma once

#include <string>

struct LoginRequest
{
	std::string _username;
	std::string _password;
};


struct SignupRequest
{
	std::string _username;
	std::string _password;
	std::string _email;
	std::string _phone;
	std::string	_date;

};





struct GameRoomData
{
	std::string _status;
	std::string _admin;
	std::string _name;

	int _maxPlayerCount;
	int _questionCount;
	int _questionTime;
};





struct GoodResponse
{
	std::string _ok = "ok";
};


struct BadResponse
{
	std::string _error;
};





struct LoginRequest
{
	std::string _username;
	std::string _password;
};


struct SignupRequest
{
	std::string _username;
	std::string _password;
	std::string _email;
};





struct GetRoomsResponse
{
	std::unordered_map<std::string, Room> _rooms;
};


struct GetPlayersInRoomResponse
{
	std::set<std::string> _players;
};





struct StartRoom
{
	std::string _roomName;
};


struct LeaveRoom
{
	std::string _use;
	std::string _roomName;
};


struct CloseRoom
{
	std::string _roomName;
};


struct RoomStatistics
{
	std::string _roomName;
};




