#include "RoomAdminRequestHandler.h"
#include "JsonRequestPacketDeserializer.h"
#include "JsonResponsePacketSerializer.h"


typedef RequestResult(RoomAdminRequestHandler::* PTR) (const Buffer& buffer);


RoomAdminRequestHandler::RoomAdminRequestHandler(RequestHandlerFactory* handleFactory):
    _handleFactory(handleFactory)
{
}


RequestResult RoomAdminRequestHandler::handleRequest(const RequestInfo& requestInfo)
{
    RequestResult r;
    return r;
}

void RoomAdminRequestHandler::closeRoom(const Buffer& buffer)
{
    //this func has gets delt with inside of Communicator it makes no sense to be here
}

void RoomAdminRequestHandler::startRoom(const Buffer& buffer)
{
    //this func has gets delt with inside of Communicator it makes no sense to be here
}