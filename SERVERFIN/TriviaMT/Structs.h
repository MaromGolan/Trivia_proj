#pragma once

#include <string>
#include <map>
#include <set>
#include <unordered_map>

#include "Room.h"
#include "GameRoomData.h"



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




//imported from MenuResponses.h;

struct GetRoomsResponse
{
	/*
	std::unordered_map<Room, std::string> _rooms;
	*/
	
};


struct GetPlayersInRoomResponse
{
	std::set<std::string> _players;
};




//classified as room requests;

struct StartRoom
{
	std::string _roomName;
};


struct LeaveRoom
{
	std::string _user;
	std::string _roomName;
};


struct CloseRoom
{
	std::string _roomName;
};


struct RoomStatusRequest
{
	std::string _roomName;
};


struct RoomStatistics
{
	std::string _roomName;
};



struct GetRoomStateResponse
{
	GameRoomData _roomData;
	std::set<std::string> _users;
};





struct Stats
{
	float _timeForAnswer;
	int _rightAnswers;
	int _wrongAnswers;
	int _gamesPlayed;
};


struct getHighScore
{
	std::multimap<int, std::string> _statistics;
};


struct getPersonalStats
{
	Stats _statistics;
};



//transfered from menuRequest.h;
struct JoinRoomRequest
{
	std::string _roomName;
	std::string _user;
};


struct GetPlayersInRoom
{
	std::string _gameRoomName;
};


struct CreateRoom
{
	GameRoomData _gameRoomData;
};



//classified as a global request;
struct LogoutRequest
{
	std::string _user;
};