#pragma once

#include <ctime>
#include <vector>
#include "jsonBase.h"

using JsonBase::Buffer;

struct RequestInfo
{
	
	int _id;
	time_t _receivalTime;
	Buffer _buffer;

};


//std::string ReqId[13] = {"LOGIN", "SIGNUP", "CREATE_ROOM", "JOIN_ROOM", "GET_PLAYERS_IN_ROOM", "GET_HIGH_SCORE,", "GET_PLAYER_STATISTICS", "LOGOUT", "GET_ROOMS", "CLOSE_ROOM", "START_ROOM", "GET_ROOM_STATE", "LEAVE_ROOM"};