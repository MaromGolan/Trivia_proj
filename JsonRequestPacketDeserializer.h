#pragma once

#include <vector>

#include "jsonBase.h"

#include "LoginRequest.h"
#include "MenuRequest.h"
#include "RoomRequest.h"


using namespace JsonBase;


class JsonRequestPacketDeserializer
{

public:

	//methods;
	static LoginRequest deserializeLoginRequest(const Buffer& buffer);
	static SignupRequest deserializeSignupRequest(const Buffer& buffer);



	//FUNCTION DECLARATIONS PREPARED FOR 2.0.0:
	static LeaveRoom deserializeLeaveRoomReq(const Buffer& buffer);
	static GetPlayersInRoom deserializeGetPlayersRequest(const Buffer& buffer);
	static CreateRoom deserializeCreateRoomRequest(const Buffer& buffer);
	static JoinRoomRequest deserializeJoinRoomRequest(const Buffer& buffer);


private:

	//constructor;
	JsonRequestPacketDeserializer() = default;

	static void toJson(const Buffer& buffer, json& jsonContainer);

};




