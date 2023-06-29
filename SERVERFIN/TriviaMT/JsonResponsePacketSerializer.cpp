#include "JsonResponsePacketSerializer.h"

#include "GameRoomData.h"
#include "Room.h"
#include "Structs.h"
#include "JsonBase.h"
#include "RoomManager.h"

#include <sstream>
#include <iostream>
#include <bitset>


//an aiding function to pack the return value of the other functions;
std::string JsonResponsePacketSerializer::returnField(const std::string& data)
{
	std::string answer;

	// setting the code to 0
	for (auto& bit : "00000000")
	{
		answer = answer + bit;
	}



	// getting the length of data in bytes
	int dataLength = data.size() * 8;


	// adding the len of data to the buffer
	for (auto& bit : std::bitset<32>(dataLength).to_string())
	{
		answer = answer + bit;
	}


	// adding the data to the buffer
	for (auto& letter : data)
	{
		for (auto& bit : std::bitset<32>(letter).to_string())
		{
			answer = answer + bit;
		}

	}

	return answer;
}


std::string JsonResponsePacketSerializer::returnDetailedField(const std::string field, const Buffer& buffer)
{
	json jsonContainer;

	JsonRequestPacketDeserializer::toJson(buffer, jsonContainer);

	return jsonContainer[field].get<std::string>();
}


//login message serializer;
std::string JsonResponsePacketSerializer::serializeLoginResponse(const GoodResponse& response)
{
	std::string answer;


	//going thru all of the bytes needed;
	for (auto& bit : response._ok)
	{
		answer = answer + bit;
	}

	return answer;
}



//sign up message serializer;
std::string JsonResponsePacketSerializer::serializeErrorResponse(const BadResponse& response)
{
	return returnField("{ \"error\" :  \"" + response._error + "\" }");
}



//a function to serialize a message regarding the data of the highest score in the room;
std::string JsonResponsePacketSerializer::serializeHighScoreResponse(const getHighScore& response)
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
std::string JsonResponsePacketSerializer::serializeGetPlayersInRoomResponse(const GetPlayersInRoomResponse& response)
{
	std::string result = "{ \"players \": [";

	for (auto& player : response._players)
	{
		result = result + "\"" + player + "\"" + ", ";
	}

	//formatting and returning the result, using the aiding formatting function;
	return returnField(result.substr(0, result.size() - 2) + " ] }");
}

std::string JsonResponsePacketSerializer::serializeGetRoomResponse(const GetRoomsResponse& response)
{

	return std::string();
}


/*
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
		temp << "{" << makeJsonPair("name", room.second) << ", " << makeJsonPair("admin", room.first.getData()._admin) << ", "
					<< makeJsonPair("state", room.first.isActive()) << ", "
					<< makeJsonPair("players_count", room.first.getAllUsers().size()) << ", "
					<< makeJsonPair("max_players", room.first.getData()._maxPlayerCount) << ", "
					<< makeJsonPair("questions_count", 10) << ", "
					<< makeJsonPair("question_timeout", room.first.getData()._questionTime) << " } ";
	}

	result = result + temp.str();


	//formatting and returning the result, just like in the previous functions;
	return returnField(result.substr(0, result.size() - 2) + " ] }");
	
}
*/

//a function to format a message regarding the state of the room;
std::string JsonResponsePacketSerializer::serializeGetRoomsStateResponse(const GetRoomStateResponse& response)
{
	std::string message;

	message = "{" + makeJsonPair("state", response._roomData._status) + ", \"players\": [ ";

	//getting the content of the message;
	for (auto& player : response._users)
	{
		message = message + "\"" + player + "\" ,";
	}


	//removing the last "," in the json message, because it can cause a syntax error;
	message.pop_back();


	//preparing the array and then formatting it before returning the data;
	message = message + "], " + makeJsonPair("answer_count", response._roomData._questionCount) + ","
		      + makeJsonPair("answer_timeout", response._roomData._questionTime) + ","
	       	  + makeJsonPair("admin", response._roomData._admin) + "}";


	return returnField(message);
}

/*
//a function to format a message regarding the closure of a room;
JsonBase::Buffer JsonResponsePacketSerializer::serializeCloseRoomResponse(const JsonBase::Buffer response)
{
	RoomManager::closeRoom(returnDetailedField("room_name", response));

	return returnField("{ \"ok \"}");
	
}
*/

//a function to format a message regarding the opening of a new game room;
std::string JsonResponsePacketSerializer::serializeStartGameResponse(const JsonBase::Buffer response)
{
    //I don't know how stuff is designed in the GUI so implement this if you can;

	return returnField("{ \"ok \"}");

}


std::string JsonResponsePacketSerializer::serializeLeaveRoomResponse(const JsonBase::Buffer response, RoomManager roomsData)
{
	LeaveRoom* newReq = new LeaveRoom();
	newReq->_roomName = returnDetailedField("room_name", response);
	newReq->_roomName = returnDetailedField("user", response);

	roomsData.RoomManager::leaveRoom(*newReq);

	return returnField("{ \"ok \"}");
}


//NOTE: it's best to not create the serializeLeaveRoomResponse function, because the action of leaving a room can be done directly at the GUI.
