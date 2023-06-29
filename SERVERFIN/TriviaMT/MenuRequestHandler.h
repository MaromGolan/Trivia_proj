#pragma once

#include "IRequestHandler.h"
#include "RequestHandlerFactory.h"
#include <iostream>



class MenuRequestHandler : public IRequestHandler
{

public:

	// Constructors
	MenuRequestHandler(RequestHandlerFactory* handleFactory);
	virtual ~MenuRequestHandler()  = default;

	// Methods
	virtual RequestResult handleRequest(const RequestInfo& requestInfo) override;
	bool isRequestRelevant(const RequestInfo request) override;
	static void createRooms(std::string data, User u);
	static std::vector<Room> getRooms(std::string data);
	static std::string getPlayersInRoom(std::string data);
	static void joinRoom(std::string data, SOCKET s);
	static void getStatistics(std::string data, SOCKET s);
	static void getHighScore(std::string data, SOCKET s);
	static void logout(std::string data);


private:

	// fields
	RequestHandlerFactory* _handleFactory;
	
	
	// Private Methods
	

};

