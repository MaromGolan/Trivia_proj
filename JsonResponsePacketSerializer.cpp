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
	for (auto& bit : response._msg)
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



//serializing a message about getting room data;
JsonBase::Buffer JsonResponsePacketSerializer::serializeResponse(const GetRoomsResponse& response)
{
	std::string msg = "{ \"rooms\" : [ ";
	std::stringstream stream;

	JsonBase::Buffer result;


	//if there is no data to return;
	if (response._rooms.empty())
	{
		//we will return an empty message;
		result = formatMessage("");
		return result;
	}

	//getting the data;
	for (auto& room : response._rooms)
	{
		stream << "{" << Pair("name", room.first) << ", " << Pair("admin", room.second.getData()._admin) << ", "
			   << Pair("state", room.second.isActive()) << ", " << Pair("players_count", room.second.getAllUsers().size()) << ", "
			   << Pair("max_players", room.second.getData()._maxPlayers) << ", " << Pair("questions_count", room.second.getData()._questionsCount) << ", "
			   << Pair("question_timeout", room.second.getData()._questionTimeout) << " }, ";
	}


	msg = msg + stream.str();

	result = formatMessage(msg.substr(0, msg.size() - 2) + " ] }");
	return result;
}



//serializing a message about getting the status of a room;
JsonBase::Buffer JsonResponsePacketSerializer::serializeResponse(const GetRoomStatus& response)
{
	JsonBase::Buffer result;

	std::string msg = "{ " + Pair("status", response._roomData._status) + " , \"players\" : [ ";

	for (auto& player : response._users)
	{
		msg = msg + "\"" + player + "\" ,";
	}

	//removing a useless char from the message;
	msg.pop_back();


	// closing array of players
	msg = msg + "], " + Pair("answer_count", response._roomData._questionCount) + "," + Pair("answer_timeout", response._roomData._questionTime) + "," + Pair("admin", response._roomData._admin) + "}";

	result = formatMessage(msg);
	return result;
}



//serializing a message about getting player data of a room;
JsonBase::Buffer JsonResponsePacketSerializer::serializeResponse(const GetPlayersInRoomResponse& response)
{
	std::string msg = "{ \"players\" : [ ";

	for (auto& player : response._players)
		msg += "\"" + player + "\"" + ", ";

	return formatMessage(msg.substr(0, msg.size() - 2) + " ] }");
}



//serializing a message about getting high scores;
JsonBase::Buffer JsonResponsePacketSerializer::serializeHighScoreResponse(const getHighScore& response)
{

	std::string msg = "{ \"high_scores\" : { ";

	//going thru all the statistics;
	for (auto stat : response._statistics)
	{
		msg = msg + Pair(stat.second, stat.first) + ", ";
	}


	JsonBase::Buffer result = formatMessage(msg.substr(0, msg.size() - 2) + " } }");

	return result;

}



//serializing a message about getting the personal statistics of a player;
JsonBase::Buffer JsonResponsePacketSerializer::serializePersonalStatsResponse(const getPersonalStats& res)
{
	return formatMessage(std::string("{ \"personal_stats\" : { ") +
		   Pair("time_for_answer", res._statistics._timeForAnswer) + ", " + Pair("right_answers", res._statistics._rightAnswers) + ", " +
		   Pair("wrong_answers", res._statistics._wrongAnswers) + ", " + Pair("games_played", res._statistics._gamesPlayed) + " } }");
}




//TO COMPLETE:


//an aiding function that will format messages for the other functions that return them;
JsonBase::Buffer JsonResponsePacketSerializer::formatMessage(const std::string& data)
{
	JsonBase::Buffer buffer;

	//obtaining the length of the data;


	//adding the data to the buffer;


	return buffer;
}