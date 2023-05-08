#pragma comment (lib, "ws2_32.lib")
#include "Server.h"
#include <thread>
#include <iostream>
#include <string>
#include <map>
#include <vector>

int main()
{
		try
		{
			
			Server s;
			std::thread t1(&Server::serve, &s, 1111);
			t1.join();
		}
		catch (const std::exception e)
		{
			std::cout << e.what()  << std::endl;
		}
	




}