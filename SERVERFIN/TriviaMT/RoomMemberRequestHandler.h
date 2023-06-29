#pragma once

#include "IRequestHandler.h"
#include "RequestHandlerFactory.h"


class RoomMemberRequestHandler : public IRequestHandler
{


public:

	// Constructors
	RoomMemberRequestHandler(RequestHandlerFactory* handleFactory);
	virtual ~RoomMemberRequestHandler() = default;
	
	// Methods
	 RequestResult handleRequest(const RequestInfo& requestInfo) override;
	 bool isRequestRelevant(const RequestInfo request) override;


private:

	// Methods
	RequestResult leaveRoom(const Buffer& buffer);
	RequestResult getRoomStatus(const Buffer& buffer);

	// Fields
	RequestHandlerFactory* _handleFactory;

};

