#pragma once

#include "GlobalResponses.h"
#include "MenuResponses.h"
#include "GameResponses.h"
#include "StatisticsOperations.h"

#include <vector>
#include <sstream>

#include "JsonBase.h"


class JsonResponsePacketSerializer
{

public:


	//reponse types;
	static JsonBase::Buffer serializeLoginResponse(const GoodResponse& response);
	static JsonBase::Buffer serializeErrorResponse(const BadResponse& response);


	//room and statistical fields;
	static JsonBase::Buffer serializeResponse(const GetRoomsResponse& response);
	static JsonBase::Buffer serializeResponse(const GetPlayersInRoomResponse& response);
	static JsonBase::Buffer serializeResponse(const GetRoomStatus& response);

	static JsonBase::Buffer serializeHighScoreResponse(const getHighScore& response);
	static JsonBase::Buffer serializePersonalStatsResponse(const getPersonalStats& response);


private:

	//constructor;
	JsonResponsePacketSerializer() = default;

	static JsonBase::Buffer formatMessage(const std::string& data);



	template<class T1, class T2>

	inline static std::string Pair(const T1& key, const T2& val);



	template<class T>

	inline static std::string Pair(const T& key, const bool val);

};



template<class T1, class T2>

inline std::string JsonResponsePacketSerializer::Pair(const T1& key, const T2& val)
{
	std::stringstream stream;
	stream << "\"" << key << "\" : \"" << val << "\"";

	return stream.str();
}



template<class T>

inline static std::string JsonResponsePacketSerializer::Pair(const T& key, const bool val)
{
	return makeJsonPair(key, val ? "True" : "False");
}

