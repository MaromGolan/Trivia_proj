#pragma once


#include "MenuResponses.h"
#include "GameResponses.h"
#include "Structs.h"

#include <vector>
#include <sstream>

#include "JsonBase.h"



class JsonResponsePacketSerializer
{

public:


	//response types;
	static JsonBase::Buffer serializeLoginResponse(const GoodResponse& response);
	static JsonBase::Buffer serializeErrorResponse(const BadResponse& response);


	static JsonBase::Buffer serializeHighScoreResponse(const getHighScore& response);
	static JsonBase::Buffer serializeGetPlayersInRoomResponse(const GetPlayersInRoomResponse& response);
	static JsonBase::Buffer serializeGetRoomResponse(const GetRoomsResponse& response);


	static JsonBase::Buffer returnField(const std::string& data);



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

	static JsonBase::Buffer returnField(const std::string& data);

	
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