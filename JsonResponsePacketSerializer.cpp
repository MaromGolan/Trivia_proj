#include "JsonResponsePacketSerializer.h"

#include "GameRoom.h"
#include "GameRoomData.h"

#include "Exception.h"

#include <sstream>
#include <iostream>



//login message serializer;
JsonBase::Buffer JsonResponsePacketSerializer::serializeLoginResponse(const GoodResponse& response)
{
	JsonBase::Buffer buffer;


	//going thru all of the bytes needed;
	for (auto& bit : response._ok)
	{
		buffer.push_back(bit);
	}

	return buffer;
}



//sign up message serializer;
JsonBase::Buffer JsonResponsePacketSerializer::serializeErrorResponse(const BadResponse& response)
{
	return formatMessage("{ \"error\" :  \"" + response._error + "\" }");
}





//the other WiP functions will be returned with 2.0.0, as a finished version;