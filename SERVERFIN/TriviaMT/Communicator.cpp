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
    pos = message.find(",\n\"message\": \"");
    i = message.substr(0,pos);
    i = i[i.length() - 1];
    do
    {
        if (i == "3")
        {
            User u;
            for (const auto& kvp : _users)
            {
                if (kvp.second == s) 
                {
                    u = kvp.first;
                }
            }
            MenuRequestHandler::createRooms(message, u);
        }

        else if (i == "4")
        {
            MenuRequestHandler::joinRoom(message, s);
            message = Receive(s);
            std::string roomname;
            pos = message.find(",\n\"message\": \"");
            message.erase(0, pos + std::string(",\n\"message\": \"").length());
            size_t found = message.find("\"\n}");
            if (found != std::string::npos && found == message.length() - 4) 
            {
                message.erase(found, 3);
            }
            roomname = message;
            User u;
            for (const auto& kvp : _users)
            {
                if (kvp.second == s)
                {
                    u = kvp.first;
                }
            }
            RoomManager::_rooms[roomname].addUser(u);
        }

        else if (i == "6")
        {
            User u;
            for (const auto& kvp : _users)
            {
                if (kvp.second == s)
                {
                    u = kvp.first;
                }
            }
            std::string response = SqliteDatabase::userStats(u.Username, this->_db);
            Send(response, s);

        }
        else if (i == "7")
        {
            std::string response = SqliteDatabase::top5stats( this->_db);
            Send(response, s);
        }
        else if (i == "10")
        {
            message.erase(0, pos + std::string(",\n\"message\": \"").length());
            size_t found = message.find("\n}");
            if (found != std::string::npos && found == message.length() - 3)
            {
                message.erase(found, 3);
            }
            SOCKET sock;
            for (int j = 0; j < RoomManager::_rooms[message].users.size(); j++)
            {
                if (RoomManager::_rooms[message].users.at(j).Username != RoomManager::_rooms[message].getData()._admin)
                {
                    for (const auto& kvp : _users)
                    {
                        if (kvp.first.Username == RoomManager::_rooms[message].users.at(j).Username)
                        {
                            Communicator::Send("{\n\"type\": 13,\n \"message\": \"admin left\"}", kvp.second);
                        }
                    }
                }
            }
            RoomManager::_rooms.erase(message);
        }
        else if (i == "11")
        {
            for (int j = 0; j < RoomManager::_rooms[message].users.size(); j++)
            {
                if (RoomManager::_rooms[message].users.at(j).Username != RoomManager::_rooms[message].getData()._admin)
                {
                    for (const auto& kvp : _users)
                    {
                        if (kvp.first.Username == RoomManager::_rooms[message].users.at(j).Username)
                        {
                            Communicator::Send("{\n\"type\": 11,\n \"message\": \"start\"}", kvp.second);
                        }
                    }
                }
            }
            for (int i = 0; i < 10; i++)
            {
                std::string question = Receive(s);
                for (int j = 0; j < RoomManager::_rooms[message].users.size(); j++)
                {
                    if (RoomManager::_rooms[message].users.at(j).Username != RoomManager::_rooms[message].getData()._admin)
                    {
                        for (const auto& kvp : _users)
                        {
                            if (kvp.first.Username == RoomManager::_rooms[message].users.at(j).Username)
                            {
                                Communicator::Send(question, kvp.second);
                            }
                        }
                    }
                }
                Send("{\n\"type\": 1,\n\"message\": \"next\"\n}", s);
            }
        }
        else if (i == "13")
        {
            message.erase(0, pos + std::string(",\n\"message\": \"").length());
            size_t found = message.find("\n}");
            if (found != std::string::npos && found == message.length() - 3)
            {
                message.erase(found, 3);
            }
            if (RoomManager::_rooms.find(message) != RoomManager::_rooms.end())
            {
                User u;
                for (const auto& kvp : _users)
                {
                    if (kvp.second == s)
                    {
                        u = kvp.first;
                    }
                }
                RoomManager::_rooms[message].removeUser(u);
            }
        }
        else if (i == "15")
        {
            pos = message.find(",\n\"message\": \"");
            message.erase(0, pos + std::string(",\n\"message\": \"").length());
            size_t found = message.find("\"\n}");

            if (found != std::string::npos && found == message.length() - 4)
            {
                message.erase(found, 3);
            }

            std::string questionText = "";
            int correctCount = 0;
            int wrongCount = 0;
            int avgTime = 0;


            pos = message.find(",");
            questionText = message.substr(0, pos);
            message.erase(0, pos + 1);

            pos = message.find(",");
            correctCount = atoi((message.substr(0, pos)).c_str());
            message.erase(0, pos + 1);

            pos = message.find(",");
            wrongCount = atoi((message.substr(0, pos)).c_str());
            message.erase(0, pos + 1);

            pos = message.find(",");
            avgTime = atoi((message.substr(0, pos)).c_str());
            message.erase(0, pos + 1);

            pos = message.find(",");
            std::string roomname = message.substr(0, pos);
            User u;
            for (const auto& kvp : _users)
            {
                if (kvp.second == s)
                {
                    u = kvp.first;
                }
            }
            RoomManager::_rooms[roomname].gm.usersgamestats[u].average_answer_time = avgTime;
            RoomManager::_rooms[roomname].gm.usersgamestats[u].correct_answer_count = correctCount;
            RoomManager::_rooms[roomname].gm.usersgamestats[u].wrong_answer_count = wrongCount;
            RoomManager::_rooms[roomname].gm.usersgamestats[u].currQuestion = questionText;
        }
        else if (i == "16")
        {
            pos = message.find(",\n\"message\": \"");
            message.erase(0, pos + std::string(",\n\"message\": \"").length());
            size_t found = message.find("\"\n}");
            bool gameended = true;
            int maxCorrect = 0;
            std::string mostcorrect;
            if (found != std::string::npos && found == message.length() - 4)
            {
                message.erase(found, 3);
            }
            User u;
            for (const auto& kvp : _users)
            {
                if (kvp.second == s)
                {
                    u = kvp.first;
                }
            }
            RoomManager::_rooms[message].gm.usersgamestats[u].finished = true;
            for (const auto& entry : RoomManager::_rooms[message].gm.usersgamestats)
            {
                const gamestats& stats = entry.second;
                if (!stats.finished)
                {
                    gameended = false;
                }
            }
            if (gameended)
            {   
                for (const auto& entry : RoomManager::_rooms[message].gm.usersgamestats)
                {
                    const gamestats& stats = entry.second;
                    if (stats.correct_answer_count > maxCorrect)
                    {
                        maxCorrect = stats.correct_answer_count;
                        mostcorrect = entry.first.Username;
                    }
                    if (stats.correct_answer_count == maxCorrect)
                    {
                        mostcorrect += "and " + entry.first.Username;
                    }
                }
                mostcorrect += " with " + std::to_string(maxCorrect) + " correct answers!";
                std::string response = "{\n\"type\": 16,\n\"message\": \"" + mostcorrect + "\"\n}";
                for (int j = 0; j < RoomManager::_rooms[message].users.size(); j++)
                {
                    for (const auto& kvp : _users)
                    {
                        if (kvp.first.Username == RoomManager::_rooms[message].users.at(j).Username)
                        {
                            Communicator::Send(response, kvp.second);
                        }
                    }
                }
            }
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
