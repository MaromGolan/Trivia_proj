#pragma once
#include "IRequestHandler.h"
#include "RequestHandlerFactory.h"
#include "RoomManager.h"

class RoomAdminRequestHandler : public IRequestHandler
{

public:

	RoomAdminRequestHandler(RequestHandlerFactory* handleFactory);
	virtual ~RoomAdminRequestHandler() = default;
	virtual RequestResult handleRequest(const RequestInfo& requestInfo) override;
	bool isRequestRelevant(const RequestInfo request) override;


private:
	
	RequestHandlerFactory* _handleFactory;
	void closeRoom(const Buffer& buffer);
	void startRoom(const Buffer& buffer);
	void getRoomState(const Buffer& buffer);


};

