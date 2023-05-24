#pragma once

#include <vector>

#include "jsonBase.h"

#include "LoginRequest.h"
#include "MenuRequest.h"
#include "RoomRequest.h"


using namespace JsonBase;


struct LogoutRequest
{
	std::string _user;
};


struct GetPersonalStatistics
{
	std::string _user;
};


class JsonRequestPacketDeserializer
{

public:

	//methods;
	static LoginRequest deserializeLoginRequest(const Buffer& buffer);
	static SignupRequest deserializeSignupRequest(const Buffer& buffer);

	static LogoutRequest deserializeLogoutReq(const Buffer& buffer);
	static GetPersonalStatistics deserializeGetPersonalStats(const Buffer& buffer);


	//room related;
	static LeaveRoom deserializeLeaveRoomReq(const Buffer& buffer);
	static GetPlayersInRoom deserializeGetPlayersRequest(const Buffer& buffer);
	static CreateRoom deserializeCreateRoomRequest(const Buffer& buffer);
	static JoinRoomRequest deserializeJoinRoomRequest(const Buffer& buffer);



private:

	//constructor;
	JsonRequestPacketDeserializer() = default;


	static void toJson(const Buffer& buffer, json& jsonContainer);

	static std::string returnField(const std::string field, const Buffer& buffer);
};




