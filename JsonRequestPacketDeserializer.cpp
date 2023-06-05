#include "JsonRequestPacketDeserializer.h"
#include "JsonResponsePacketSerializer.h"

#include "Structs.h"

#include <string>
#include <bitset>
#include <sstream>



//an aiding function to ease the returning of a field, in other functions;
std::string JsonRequestPacketDeserializer::returnField(const std::string field, const Buffer& buffer)
{
    json jsonContainer;
    toJson(buffer, jsonContainer);

    return jsonContainer[field].get<std::string>();
}



//a function to deserialize the login request;
LoginRequest JsonRequestPacketDeserializer::deserializeLoginRequest(const Buffer& buffer)
{

    json jsonContainer;
    toJson(buffer, jsonContainer);

    return LoginRequest{ jsonContainer["username"].get<std::string>(), jsonContainer["password"].get<std::string>() };

}


//a function to deserialize the signup request;
SignupRequest JsonRequestPacketDeserializer::deserializeSignupRequest(const Buffer& buffer)
{

    json jsonContainer;
    toJson(buffer, jsonContainer);

    return {jsonContainer["username"].get<std::string>(), jsonContainer["password"].get<std::string>(), jsonContainer["email"].get<std::string>()};

}


//a function to make a json container from the data;
void JsonRequestPacketDeserializer::toJson(const Buffer& buffer, json& jsonContainer)
{

    std::string bufferStr = "";
    std::stringstream buffstream(bufferStr);

    std::bitset<4> byte;
    std::string jsonResult;

    //the buffer will be a stream;
    for (auto& bit : buffer)
    {
        bufferStr = bufferStr + bit;
    }

    //obtaining all of the data;
    while (buffstream.good())
    {
        buffstream >> byte;

        jsonResult = jsonResult + char(byte.to_ulong());
    }

    jsonContainer = json::parse(jsonResult);
}


//function needed in 2.0.0;
GetPlayersInRoom JsonRequestPacketDeserializer::deserializeGetPlayersRequest( const Buffer& buffer)
{
    return {returnField("room_name" , buffer)}; //we can easily the use the helping function for it;

}


//function needed in 2.0.0;
JoinRoomRequest JsonRequestPacketDeserializer::deserializeJoinRoomRequest(const Buffer& buffer)
{
    json jsonContainer;
    toJson(buffer, jsonContainer);

    
    return JoinRoomRequest{jsonContainer["room_name"].get<std::string>(), jsonContainer["username"].get<std::string>()};
}


//function needed in 2.0.0, to create a request for creating a room;
CreateRoom JsonRequestPacketDeserializer::deserializeCreateRoomRequest(const Buffer& buffer)
{
    json jsonContainer;
    toJson(buffer, jsonContainer);

    return { {jsonContainer["creator"].get<std::string>(), jsonContainer["room_name"].get<std::string>(), "Waiting", //because there is no name yetl
            jsonContainer["max_users"].get<int>(), jsonContainer["questions_count"].get<int>(), jsonContainer["answer_timeout"].get<int>() } };
}
