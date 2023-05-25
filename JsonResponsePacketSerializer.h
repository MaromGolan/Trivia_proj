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

	//preparing for 2.0.0:
	static JsonBase::Buffer serializeHighScoreResponse(const getHighScore& response);
	static JsonBase::Buffer serializePersonalStatsResponse(const getPersonalStats& response);


private:

	//constructor;
	JsonResponsePacketSerializer() = default;

	static JsonBase::Buffer formatMessage(const std::string& data);


};