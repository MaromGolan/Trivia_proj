#include "LoginRequestHandler.h"
#include "JsonRequestPacketDeserializer.h"
#include "JsonResponsePacketSerializer.h"
#include "MenuRequestHandler.h"

#include "structs.h"

#include <memory>

using std::shared_ptr;
using std::string;



//? Constructors ?//


/* -- c'tor -- */
LoginRequestHandler::LoginRequestHandler( LoginManager* loginManager, 
										  RequestHandlerFactory* factory) :
	_loginManager(loginManager), _handleFactory(factory)
{
}



//? Methods ?//


/*
	-- handle the current request - analyze the request info 
	   and return a suited response --
	* input: current request's info
	* output: request's result
*/
RequestResult LoginRequestHandler::handleRequest(const RequestInfo& requestInfo)
{

	if (requestInfo._id == 1)
	{
		return handleLoginRequest(requestInfo._buffer);
	}

		
	if (requestInfo._id == 2)
	{
		return handleSignupRequest(requestInfo._buffer);
	}

	return handleBadRequest();

}

/*
	-- handle signup request --
	* input: buffer
	* output: request's result
*/
RequestResult LoginRequestHandler::handleSignupRequest(const Buffer& buffer)
{

	// deserialize the message from json format 
	SignupRequest request = JsonRequestPacketDeserializer::deserializeSignupRequest(buffer);

	std::shared_ptr<IRequestHandler> nextHandler;


	_loginManager->signup(request);

	return {
		JsonResponsePacketSerializer::serializeLoginResponse(GoodResponse()),
		_handleFactory->createMenuRequestHandler()
	};
	
}

/*
	-- handle login request --
	* input: buffer
	* output: request's result
*/
RequestResult LoginRequestHandler::handleLoginRequest(const Buffer& buffer)
{

	// deserialize the message from json format 
	LoginRequest request = JsonRequestPacketDeserializer::deserializeLoginRequest(buffer);


	_loginManager->login(request);

	return {
		JsonResponsePacketSerializer::serializeLoginResponse(GoodResponse()),
		_handleFactory->createMenuRequestHandler()
	};


}

RequestResult LoginRequestHandler::handleBadRequest(const string& errorMessage,
	const bool returnLoginRequest)
{

	return {
		JsonResponsePacketSerializer::serializeErrorResponse(BadResponse{errorMessage}),
		(returnLoginRequest ? _handleFactory->createLoginRequestHandler() : nullptr)
	};

}


bool isRequestRelevant(const RequestInfo request)
{
	//to complete;
	return true;
}
