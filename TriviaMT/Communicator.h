#pragma once
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <unordered_map>
#include "User.h"
#include "IRequestHandler.h"
#include <thread>
#include "IDataBase.h"
#include "SqliteDataBase.h"
#include <string>
#pragma comment(lib, "ws2_32.lib")

class Communicator {
public:
    Communicator();
    ~Communicator();
    void start();
    bool Initialize();
    bool CreateSocket();
    bool Bind(const std::string& ipAddress, int port);
    bool Listen(int backlog);
    void Accept();
    void handle(SOCKET s);
    std::string Receive(SOCKET s);
    bool Send(const std::string& message,SOCKET s);
    static bool Send(const std::string& message, SOCKET s);
    void core(SOCKET s);
    void Close();
    std::string dbname;
    sqlite3* _db;
    static std::unordered_map<User, SOCKET> _users;

private:
    std::shared_ptr<IDatabase> db;
    WSADATA wsaData;
    SOCKET serverSocket;
    SOCKET clientSocket;
    struct sockaddr_in serverAddress;
    struct sockaddr_in clientAddress;
   

};
