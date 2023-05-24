#pragma once

#include <mutex>
#include "RequestHandlerFactory.h"
#include "JsonBase.h"




class Communicator
{

public:
	
	void run();


private:

	Communicator(RequestHandlerFactory* handlerFactory);

	void print(const std::string& output);

	static constexpr const char* IP = "127.0.0.1";
	static constexpr int PORT = 8826;

	static constexpr int MESSAGE_CODE_SIZE = 1;
	static constexpr int MESSAGE_LENGTH_SIZE = 4;

	static constexpr const char* EXIT_MESSAGE = "exit";

	std::mutex _printMutex;

	RequestHandlerFactory* _handlerFactory;
	
	bool _exit;

};




