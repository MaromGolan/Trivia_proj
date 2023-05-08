#include "Server.h"
#include <exception>
#include <iostream>
#include <string>
#include <thread>
#include "Helper.h"
#include <algorithm>
#pragma warning(disable : 4996)
std::string zeros = "000000000000";
int lengthOfZeros = zeros.length();
Server::Server()
{

	// this server use TCP. that why SOCK_STREAM & IPPROTO_TCP
	// if the server use UDP we will use: SOCK_DGRAM & IPPROTO_UDP
	_serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (_serverSocket == INVALID_SOCKET)
		throw std::exception(__FUNCTION__ " - socket");
}

Server::~Server()
{

	try
	{
		// the only use of the destructor should be for freeing 
		// resources that was allocated in the constructor
		closesocket(_serverSocket);
	}
	catch (...)
	{

	}
}

void Server::serve(int port)
{

	struct sockaddr_in sa = { 0 };

	sa.sin_port = htons(port); // port that server will listen for
	sa.sin_family = AF_INET;   // must be AF_INET
	sa.sin_addr.s_addr = INADDR_ANY;    // when there are few ip's for the machine. We will use always "INADDR_ANY"

	// Connects between the socket and the configuration (port and etc..)
	if (bind(_serverSocket, (struct sockaddr*)&sa, sizeof(sa)) == SOCKET_ERROR)
		throw std::exception(__FUNCTION__  " - bind");

	// Start listening for incoming requests of clients
	if (listen(_serverSocket, SOMAXCONN) == SOCKET_ERROR)
		throw std::exception(__FUNCTION__  " - listen");
	std::cout << "Listening on port " << port << std::endl;
	std::cout << "waiting\n";
	while (true)
	{

		// the main thread is only accepting clients 
		// and add then to the list of handlers
		//std::cout << "Waiting for client connection request" << std::endl;
		std::thread t1(&Server::acceptClient, this, _serverSocket);
		t1.detach();
		//acceptClient(_serverSocket);
	}
}

/*
func finds users
*/
std::map<std::string, SOCKET>::iterator Server::userFinder(std::string username)
{
	std::map<std::string, SOCKET>::iterator curr;
	try
	{
		std::unique_lock<std::mutex> lckUsers(_mUsers, std::defer_lock);
		for (std::map<std::string, SOCKET>::iterator it = users.begin(); it != users.end(); it++)
		{
			if (it->first == username)
			{
				curr = it;
				break;
			}
		}
		lckUsers.unlock();
	}
	catch (const std::exception& e)
	{
		closesocket(curr->second);
		userDeleter(username);
	}
	return curr;
}
/*
func deletes
*/
void Server::userDeleter(std::string username)
{
	std::map<std::string, SOCKET>::iterator curr;
	for (std::map<std::string, SOCKET>::iterator it = users.begin(); it != users.end(); it++)
	{
		if (it->first == username)
		{
			users.erase(it);
			break;
		}
	}
}
/*
this func helps update the users shown on screen
*/
void Server::dataSender(SOCKET clientSocket)
{
	while (true)
	{
		std::string msg = "hello";
		{
			send(clientSocket, msg.c_str(), 5, 0);  // last parameter: flag. for us will be 0.
		}
		char buffer[1024];
		int bytes_received = recv(clientSocket, buffer, sizeof(buffer), 0);
		std::string received_message(buffer, bytes_received);
		std::cout << "Received message: " << received_message << std::endl;
	}
}
/*
writes to file
*/
void Server::fileWriter(std::ofstream& file, std::string msg, std::string username)
{
	std::string filemsg = "&MAGSH_MESSAGE&&Author&" + username + "&DATA&" + msg;
	file << filemsg;
}


/*
this func gets the msg and sends it to the file and to the user
*/
void Server::msgFixer(SOCKET s, std::string username)
{

	std::string path;
	std::string un2;
	std::string data;
	int sulength = 0, dlength = 0;
	while (true)
	{
		int i = 0, index = 0;
		try
		{
			std::string msg = "";
			while (s != INVALID_SOCKET)
			{
				msg = Helper::getStringPartFromSocket(s, 10000);
				if (msg.substr(0, 3) == "204")
				{
					sulength = 10 * (msg[3] - 48) + (msg[4] - 48);
					un2 = msg.substr(5, sulength);
					dlength += 10000 * (msg[sulength + 5] - 48);
					dlength += 1000 * (msg[sulength + 5 + 1] - 48);
					dlength += 100 * (msg[sulength + 5 + 2] - 48);
					dlength += 10 * (msg[sulength + 5 + 3] - 48);
					dlength += (msg[sulength + 5 + 4] - 48);
					if (dlength != 0)
					{
						data += msg.substr(5 + sulength + 5, dlength);
						if (username > un2)
						{
							path = un2 + '&' + username;
						}
						else
						{
							path = username + '&' + un2;
						}
						path += ".txt";
						std::ofstream file(path, std::ios::out | std::ios::app);
						fileWriter(file, data, username);
						file.close();
						std::unique_lock<std::mutex> lck(_mMessages);
						_messages.push(msg);
						lck.unlock();
						data = "";
						dlength = 0;
					}
				}
			}
		}
		catch (const std::exception& e)
		{
			closesocket(s);
			userDeleter(username);
		}
	}
}
/*
this func updates the users shown on screen
*/
void Server::userUpdator(SOCKET s, std::string username)
{
	std::string names;
	std::vector<std::string> vnames;
	int uindex = 0, i = 0;
	for (std::map<std::string, SOCKET>::iterator it = users.begin(); it != users.end(); it++)
	{
		vnames.push_back(it->first);
	}
	for (int i = 0; i < vnames.size(); i++)
	{
		names += vnames.at(i);
		if (vnames.at(i) != vnames.at(vnames.size() - 1))
			names += '&';
	}
	Helper::send_update_message_to_client(s, "", vnames.at(0), names);
	names = "";
	vnames.clear();
}


void Server::acceptClient(SOCKET s)
{

	// this accepts the client and create a specific socket from server to this client
	// the process will not continue until a client connects to the server
	SOCKET client_socket = accept(s, NULL, NULL);
	if (client_socket == INVALID_SOCKET)
		throw std::exception(__FUNCTION__ );

	std::cout << "Client accepted. Server and client can speak" << std::endl;
	// the function that handle the conversation with the client
	clientHandler(client_socket);
}


void Server::clientHandler(SOCKET clientSocket)
{
	//std::pair<std::string, SOCKET> client;
	try
	{
		std::string name = "currnothing";
		std::string nlength;
		char m[100];
		std::unique_lock<std::mutex> lck(_mUsers);
		this->users.insert({ name,clientSocket });
		lck.unlock();
		std::thread dataSender(&Server::dataSender, this, clientSocket);
		dataSender.detach();
		// going to data sender and after data sender using recv to get the hello user should send
	}
	catch (const std::exception& e)
	{
		closesocket(clientSocket);
	}
}