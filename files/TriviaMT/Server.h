#pragma once

#include <WinSock2.h>
#include <Windows.h>
#include <map>
#include <queue>
#include <set>
#include <mutex>
#include <sstream>
#include <fstream>
class Server
{
public:
	Server();
	~Server();
	void serve(int port);
	void msgFixer(SOCKET s, std::string username);
	void userUpdator(SOCKET s, std::string username);
	std::map<std::string, SOCKET>::iterator userFinder(std::string username);
	void userDeleter(std::string username);
	void dataSender(SOCKET clientSocket);
	void fileWriter(std::ofstream& file, std::string msg, std::string username);

private:

	void acceptClient(SOCKET s);
	void clientHandler(SOCKET clientSocket);

	SOCKET _serverSocket;
	//std::vector<std::pair<std::string, SOCKET>> users;
	std::map<std::string, SOCKET> users;
	std::mutex _mUsers;
	std::mutex _mMessages;
	std::condition_variable _cvMessages;
	std::queue<std::string> _messages;
};