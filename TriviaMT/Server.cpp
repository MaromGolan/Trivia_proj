#include "Server.h"
#include <thread>
#include "Communicator.h"

void Server::run()
{
	try
	{
		Communicator s;
		std::thread t1(&Communicator::start, &s);
		t1.join();
	}
	catch (const std::exception e)
	{
		std::cout << e.what() << std::endl;
	}

};
