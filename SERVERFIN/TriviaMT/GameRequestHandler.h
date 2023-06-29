#pragma once

#include "IRequestHandler.h"

#include "Room.h"
#include "User.h"
#include "Structs.h"
#include "GameRoomData.h"

#include "RequestHandlerFactory.h"
#include "RequestResult.h"
#include "JsonRequestPacketDeserializer.h"
#include "JsonResponsePacketSerializer.h"
#include "MenuRequestHandler.h"
#include "Communicator.h"

#include "GameManager.h"


class GameRequestHandler : public IRequestHandler
{

public:


	GameRequestHandler(Room room, User user);
	~GameRequestHandler();

	bool isRequestRelevant(const RequestInfo request) override;

	RequestResult handleRequest(const RequestInfo& request) override;



private:

	Room* _room;
	User* _user;
	RequestHandlerFactory _handlerFactory;

	GameManager _manager;

	std::string LeaveGameRequest(std::string request, SOCKET s);
	std::string GetQuestionRequest(std::string request, SOCKET s);
	std::string SubmitAnswerRequest(std::string request, SOCKET s);
	std::string GetGameResultRequest(std::string request, SOCKET s);

};