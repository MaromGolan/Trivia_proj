#include "RoomMemberRequestHandler.h"
#include "JsonRequestPacketDeserializer.h"
#include "JsonResponsePacketSerializer.h"

//from the structs file, we will obtain our many structs, and from the InvalidReq file, we will obtain the specific exception for an invalid request;
#include "Structs.h"
#include "GameRoomData.h"
#include "RequestInfo.h"


typedef RequestResult(RoomMemberRequestHandler::* PTR) (const Buffer& buffer);


RoomMemberRequestHandler::RoomMemberRequestHandler(RequestHandlerFactory* handleFactory): _handleFactory(handleFactory)
{

}


/*
//a function to determine if the request is valid, else we will face an error;
bool RoomMemberRequestHandler::isRequestValid(const RequestInfo& requestInfo)
{
    for (int requestID : { 11, 12 })
    {
        if (requestID == requestInfo._id)
        {
            return true;
        }

    }

    //else;
    return false;
}
*/

//a function to handle the request of getting the status of a room;
RequestResult RoomMemberRequestHandler::getRoomStatus(const Buffer& buffer)
{
    std::string roomName = JsonRequestPacketDeserializer::deserializeRoomStateReq(buffer)._roomName;
    GameRoomData roomData = _handleFactory->getRoomManager()->getRoomData(roomName);

    return
    {
        JsonResponsePacketSerializer::serializeGetRoomsStateResponse({ roomData, _handleFactory->getRoomManager()->getPlayersInRoom(roomName)}),
        roomData._status == "closed" ? _handleFactory->createMenuRequestHandler() : _handleFactory->createRoomMemberRequestHandler()
    };
}



//a function to handle a request of any sort;
RequestResult RoomMemberRequestHandler::handleRequest(const RequestInfo& requestInfo)
{
    int i = 0;
    int requestID = 0;


    //if the request is invalid, we will print an error;

    //else;

    PTR handlers[] =
    {
        &RoomMemberRequestHandler::leaveRoom,
        &RoomMemberRequestHandler::getRoomStatus,
    };

    for (int requestID : { 11, 12 })
    {
        if (requestID == requestInfo._id)
        {
            return (this->*handlers[i])(requestInfo._buffer);
        }


        ++i;
    }

    return {};
}


//a function to handle the request of leaving a room;
RequestResult RoomMemberRequestHandler::leaveRoom(const Buffer& buffer)
{
    //using the handle factory to get our room manager, from which, we will update the room data to correspond with the departure of a member;
    _handleFactory->getRoomManager()->leaveRoom(JsonRequestPacketDeserializer::deserializeLeaveRoomReq(buffer));

    return
    { 
        JsonResponsePacketSerializer::serializeLoginResponse(GoodResponse{}), 
        _handleFactory->createMenuRequestHandler() 
    };

}