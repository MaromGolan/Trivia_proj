#include "Communicator.h"
#include "LoginManager.h"
#include "Structs.h"
#include "MenuRequestHandler.h"
#pragma warning(suppress : 4996)
std::unordered_map<User, SOCKET> Communicator::_users;

Communicator::Communicator() : serverSocket(INVALID_SOCKET), clientSocket(INVALID_SOCKET)  
{
    this->dbname = "Filename.DB";
    SqliteDatabase::openDatabase(this->_db,this->dbname);
}

Communicator::~Communicator() {
    Close();
}

void Communicator::start()
{
   
    if (!this->Initialize())
    {
        
    }
    
    if (!this->CreateSocket())
    {
        
    }
    
    if (!this->Bind("127.0.0.1", 8826))
    {
    
    }
    
    if (!this->Listen(5))
    { 
    }

    while (true)
    {
       std::thread t1(&Communicator::Accept, this);
       t1.detach();
    }
}

bool Communicator::Initialize() {
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Failed to initialize winsock" << std::endl;
        return false;
    }
    return true;
}

bool Communicator::CreateSocket() {
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        std::cerr << "Failed to create socket" << std::endl;
        return false;
    }
    return true;
}

bool Communicator::Bind(const std::string& ipAddress, int port) {
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr(ipAddress.c_str());
    serverAddress.sin_port = htons(port);
    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
        std::cerr << "Failed to bind to address" << std::endl;
        return false;
    }
    return true;
}

bool Communicator::Listen(int backlog) {
    if (listen(serverSocket, backlog) == SOCKET_ERROR) {
        std::cerr << "Failed to listen for connections" << std::endl;
        return false;
    }
    return true;
}
void Communicator::core(SOCKET s)
{
    std::string i = "777";
    std::string message = Receive(s), type, username, password, seperator = ",";
    size_t pos = 0;
    pos = message.find(seperator);
    type = message.substr(0, pos);

    i = type[type.length()-2];
    do
    {
        if (i == "3")
        {
            User u;
            for (const auto& kvp : _users) {
                if (kvp.second == s) {
                    u = kvp.first;
                }
            }
            MenuRequestHandler::createRooms(message, u);
        }

        if (i == "4")
        {
            MenuRequestHandler::joinRoom(message, s);
            message = Receive(s);
            std::string roomname;
            pos = message.find(",\n\"message\": \"");
            message.erase(0, pos + std::string(",\n\"message\": \"").length());
            size_t found = message.find("\n}");
            if (found != std::string::npos && found == message.length() - 3) {
                message.erase(found, 3);
            }
            roomname = message;

            for (const auto& kvp : RoomManager::_rooms) {
                if (kvp.first == message) {
                    
                }
            }
        }

        if (i == "5")
        {
            //
        }

        if (i == "6")
        {

        }

        if (i == "9")
        {
            //
        }

        if (i == "10")
        {

        }

        if (i == "11")
        {

        }

        if (i == "12")
        {

        }

        if (i == "13")
        {

        }

        if (i == "14")
        {

        }

        if (i == "15")
        {

        }

        if (i == "16")
        {

        }

        if (i == "17")
        {
            //
        }

        if (i == "18")
        {
            //
        }

        if (i == "19")
        {
            //
        }

    } while (i != "8");
}

void Communicator::Accept()
{
    int clientLength = sizeof(clientAddress);

    SOCKET clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientLength);

    if (clientSocket == INVALID_SOCKET) 
    {
        std::cerr << "Failed to accept client connection" << std::endl;
    }
    this->handle(clientSocket);
}



void Communicator::handle(SOCKET s)
{
    std::string message = this->Receive(s),type, username, password,seperator = ",";
    size_t pos = 0; 
    pos = message.find(",\n\"message\": \"");
    type = message.substr(0, pos);
    type = type[type.length()-1];
    message.erase(0, pos + std::string(",\n\"message\": \"").length());
    bool existed = true;//with this bool we check if the user exists in the DB for the login and the sign up
    pos = message.find(seperator);
    type = message.substr(0, pos);

    message.erase(0, pos + seperator.length());

    pos = message.find(seperator);
    username = message.substr(0, pos);

    message.erase(0, pos + seperator.length());

    pos = message.find(seperator);
    username = message.substr(0, pos);

    message.erase(0, pos + seperator.length());

    if (type == "2")
    {
        pos = message.find(seperator);

        std::string email = message.substr(0, pos);

        message.erase(0, pos + seperator.length());
        LoginManager lm(this->db);
        SignupRequest signup;

        signup._username = username;
        signup._password = password;
        signup._email= email;
        lm.signup(signup);

        User u(username, password,email);

        this->_users.insert({ u,s });
    }
    else
    {
        LoginManager lm(this->db);
        LoginRequest login;
        login._username = username;
        login._password = password;

        lm.login(login);
        std::string email = SqliteDatabase::emailOfUser(username,this->_db);

        User u(username, password, email);
        this->_users.insert({ u,s });
    }


}
    

std::string Communicator::Receive(SOCKET s) {
    char buffer[10240];
    std::string message;
    memset(buffer, 0, sizeof(buffer));
    int bytesRead = recv(s, buffer, sizeof(buffer), 0);
    if (bytesRead == SOCKET_ERROR) {
        std::cerr << "Failed to read from socket" << std::endl;
    }
    return buffer;
}

bool Communicator::Send(const std::string& message, SOCKET s)
{
    int bytesSent = send(s, message.c_str(), static_cast<int>(message.length()), 0);


    if (bytesSent == SOCKET_ERROR) {
        std::cerr << "Failed to write to socket" << std::endl;
        return false;
    }

    return true;
}

bool Communicator::Send(const std::string& message, SOCKET s)
{
    int bytesSent = send(s, message.c_str(), static_cast<int>(message.length()), 0);


    if (bytesSent == SOCKET_ERROR) {
        std::cerr << "Failed to write to socket" << std::endl;
        return false;
    }

    return true;
}

void Communicator::Close() {
    if (clientSocket != INVALID_SOCKET) {
        closesocket(clientSocket);
        clientSocket = INVALID_SOCKET;
    }
    if (serverSocket != INVALID_SOCKET) {
        closesocket(serverSocket);
        serverSocket = INVALID_SOCKET;
    }
    WSACleanup();
}
