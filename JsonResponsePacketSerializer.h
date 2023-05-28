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


	//sreponse types;
	static JsonBase::Buffer serializeLoginResponse(const GoodResponse& response);
	static JsonBase::Buffer serializeErrorResponse(const BadResponse& response);



	//preparing for 2.0.0:
	static JsonBase::Buffer serializeHighScoreResponse(const getHighScore& response);
	static JsonBase::Buffer serializePersonalStatsResponse(const getPersonalStats& response);



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

	static JsonBase::Buffer formatMessage(const std::string& data);


};