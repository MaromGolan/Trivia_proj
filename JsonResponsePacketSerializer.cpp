#include "JsonResponsePacketSerializer.h"

#include "GameRoom.h"
#include "Structs.h"
#include "Exception.h"
#include "JsonBase.h"

#include <sstream>
#include <iostream>
#include <bitset>




//an aiding function to pack the return value of the other functions;
JsonBase::Buffer JsonResponsePacketSerializer::returnField(const std::string& data)
{
	JsonBase::Buffer buffer;

	// setting the code to 0
	for (auto& bit : "00000000")
	{
		buffer.push_back(bit);
	}



	// getting the length of data in bytes
	int dataLength = data.size() * 8;


	// adding the len of data to the buffer
	for (auto& bit : std::bitset<32>(dataLength).to_string())
	{
		buffer.push_back(bit);
	}


	// adding the data to the buffer
	for (auto& letter : data)
	{
		for (auto& bit : std::bitset<32>(letter).to_string())
		{
			buffer.push_back(bit);
		}

	}

	return buffer;
}



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
	return returnField("{ \"error\" :  \"" + response._error + "\" }");
}



//a function to serialize a message regarding the data of the highest score in the room;
JsonBase::Buffer JsonResponsePacketSerializer::serializeHighScoreResponse(const getHighScore& response)
{
	std::string result = "{ \"high_scores \": {";

	for (auto stat : response._statistics)
	{
		result = result + makeJsonPair(stat.second, stat.first) + ", ";
	}


	//formatting and returning the result, using the aiding formatting function;
	return returnField(result.substr(0, result.size() - 2) + " } }");
}



//a function to serialize a message regarding the data of the players of the room;
JsonBase::Buffer JsonResponsePacketSerializer::serializeGetPlayersInRoomResponse(const GetPlayersInRoomResponse& response)
{
	std::string result = "{ \"players \": [";

	for (auto& player : response._players)
	{
		result = result + "\"" + player + "\"" + ", ";
	}

	//formatting and returning the result, using the aiding formatting function;
	return returnField(result.substr(0, result.size() - 2) + " ] }");
}



//a function to serialize a message regarding the data of the rooms;
JsonBase::Buffer JsonResponsePacketSerializer::serializeGetRoomResponse(const GetRoomsResponse& response)
{
	std::string result = "{ \"Rooms \": [";
	std::stringstream temp;

	//if there are no rooms to return;
	if (response._rooms.empty())
	{
		return returnField("");
	}

	//adding the data of each room that exists, into the temporary stream, which will be converted to the message we will format and return;
	for (auto& room : response._rooms)
	{
		temp << "{" << makeJsonPair("name", room.first) << ", " << makeJsonPair("admin", room.second.getData()._admin) << ", "
					<< makeJsonPair("state", room.second.isActive()) << ", "
					<< makeJsonPair("players_count", room.second.getAllUsers().size()) << ", "
					<< makeJsonPair("max_players", room.second.getData()._maxPlayerCount) << ", "
					<< makeJsonPair("questions_count", room.second.getData()._questionCount) << ", "
					<< makeJsonPair("question_timeout", room.second.getData()._questionTime) << " }, ";
	}

	result = result + temp.str();


	//formatting and returning the result, just like in the previous functions;
	return returnField(result.substr(0, result.size() - 2) + " ] }");
}
