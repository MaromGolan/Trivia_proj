#pragma once

#include "JsonRequestPacketDeserializer.h"

#include "MenuResponses.h"
#include "GameResponses.h"
#include "RoomManager.h"
#include "Structs.h"

#include <vector>
#include <sstream>

#include "JsonBase.h"



class JsonResponsePacketSerializer
{

public:


	//response types;
	static std::string serializeLoginResponse(const GoodResponse& response);
	static std::string serializeErrorResponse(const BadResponse& response);


	static std::string serializeHighScoreResponse(const getHighScore& response);
	static std::string serializeGetPlayersInRoomResponse(const GetPlayersInRoomResponse& response);
	static std::string serializeGetRoomResponse(const GetRoomsResponse& response);

	static std::string serializeGetRoomsStateResponse(const GetRoomStateResponse& response);
	static std::string serializeCloseRoomResponse(const JsonBase::Buffer response);
	static std::string serializeStartGameResponse(const JsonBase::Buffer response);
	static std::string serializeLeaveRoomResponse(const JsonBase::Buffer response, RoomManager roomsData);


	static std::string returnField(const std::string& data);



	//the singleton bonus;

	JsonResponsePacketSerializer(JsonResponsePacketSerializer const&) = delete;

	void operator=(JsonResponsePacketSerializer const&) = delete;

	static JsonResponsePacketSerializer& getInstance()
	{
		static JsonResponsePacketSerializer entity;

		return entity;
	}


private:

	//constructor;
	JsonResponsePacketSerializer() = default;

	static std::string returnDetailedField(const std::string field, const Buffer& buffer);

	
	//template declarations;
	template<class T1, class T2> inline static std::string makeJsonPair(const T1& key, const T2& val);
	template<class T> inline static std::string makeJsonPair(const T& key, const bool val);

};


//the templates:

template<class T1, class T2> inline std::string JsonResponsePacketSerializer::makeJsonPair(const T1& key, const T2& val)
{
	std::stringstream stream;
	stream << "\"" << key << "\" : \"" << val << "\"";

	return stream.str();
}

template<class T> inline static std::string JsonResponsePacketSerializer::makeJsonPair(const T& key, const bool val)
{
	return makeJsonPair(key, val ? "True" : "False");
}

//the use of the templates will help to create the functions in the .cpp file;