#pragma once
#include "GameRoomData.h"


struct GetRoomStatus
{
    GameRoomData _roomData;
    std::set<std::string> _users;
};