#pragma once

#include <vector>
#include <string>

#include "Structs.h"
#include "jsonBase.h"

using namespace JsonBase;


class JsonRequestPacketDeserializer
{

public:


	//methods;
	static LoginRequest deserializeLoginRequest(const Buffer& buffer);
	static SignupRequest deserializeSignupRequest(const Buffer& buffer);

	static GetPlayersInRoom deserializeGetPlayersRequest(const Buffer& buffer);
	static CreateRoom deserializeCreateRoomRequest(const Buffer& buffer);
	static JoinRoomRequest deserializeJoinRoomRequest(const Buffer& buffer);


	static std::string returnField(const std::string field, const Buffer& buffer);



	//the singleton bonus;

	JsonRequestPacketDeserializer(JsonRequestPacketDeserializer const&) = delete;

	void operator=(JsonRequestPacketDeserializer const&) = delete;

	static JsonRequestPacketDeserializer& getInstance()
	{
		static JsonRequestPacketDeserializer entity;

		return entity;
	}


private:

	//constructor;
	JsonRequestPacketDeserializer() = default;

	//this is similar to "toString" in cs;
	static void toJson(const Buffer& buffer, json& jsonContainer);

};




