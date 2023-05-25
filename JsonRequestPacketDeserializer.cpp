#include "JsonRequestPacketDeserializer.h"
#include "JsonResponsePacketSerializer.h"
#include "Structs.h"

#include <string>
#include <bitset>
#include <sstream>





LoginRequest JsonRequestPacketDeserializer::deserializeLoginRequest(const Buffer& buffer)
{

    json jsonContainer;
    toJson(buffer, jsonContainer);

    return LoginRequest{ jsonContainer["username"].get<std::string>(),
                          jsonContainer["password"].get<std::string>() };

}


SignupRequest JsonRequestPacketDeserializer::deserializeSignupRequest(const Buffer& buffer)
{

    json jsonContainer;
    toJson(buffer, jsonContainer);

    return
    {
        jsonContainer["username"].get<std::string>(), jsonContainer["password"].get<std::string>(), jsonContainer["email"].get<std::string>(),
        jsonContainer["phone"].get<std::string>(), jsonContainer["date"].get<std::string>()
    };

}



void JsonRequestPacketDeserializer::toJson(const Buffer& buffer, json& jsonContainer)
{

    std::string bufferString = "";

    // setting the buffer as a stream
    for (auto& bit : buffer)
        bufferString += bit;


    std::stringstream buffstream(bufferString);

    std::bitset<4> byte;
    std::string jsonStringHolder;

    //obtaining all of the data;
    while (buffstream.good())
    {

        buffstream >> byte;

        jsonStringHolder = jsonStringHolder + char(byte.to_ulong());

    }


    jsonContainer = json::parse(jsonStringHolder);

}
