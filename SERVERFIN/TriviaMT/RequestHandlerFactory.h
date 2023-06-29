#pragma once

#include "IDatabase.h"
#include "IRequestHandler.h"
#include "LoginManager.h"
#include "RoomManager.h"

class LoginRequestHandler;

class RequestHandlerFactory
{

public:

	// Constructors 
	RequestHandlerFactory() = default;
	RequestHandlerFactory(std::shared_ptr<IDatabase>& database);

	// Methods
	std::shared_ptr<IRequestHandler> createLoginRequestHandler();
	std::shared_ptr<IRequestHandler> createMenuRequestHandler();
	std::shared_ptr<IRequestHandler> createRoomAdminRequestHandler();
	std::shared_ptr<IRequestHandler> createRoomMemberRequestHandler();


	// Getters
	LoginManager* getLoginManager() { return _loginManager; };
	RoomManager* getRoomManager() { return _roomManager; };


private:


	// Fields
	LoginManager* _loginManager;
	RoomManager* _roomManager;

	std::shared_ptr<IDatabase> _database;

};

