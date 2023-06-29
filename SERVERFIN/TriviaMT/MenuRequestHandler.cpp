#include "MenuRequestHandler.h"
#include "JsonRequestPacketDeserializer.h"
#include "JsonResponsePacketSerializer.h"
#include "User.h"
#include "Structs.h"
#include "Communicator.h"

typedef RequestResult(MenuRequestHandler::* PTR) (const Buffer& buffer);

MenuRequestHandler::MenuRequestHandler(RequestHandlerFactory* handleFactory) :
    _handleFactory(handleFactory)
{
}



void MenuRequestHandler::createRooms(std::string data, User u)
{
    GameRoomData r;
    std::string name, dat, seperator = ",";
    int timePerQuestion, NumOfPlayers;
    size_t pos = 0;
    pos = data.find(",\n\"message\": \"");
    data.erase(0, pos + std::string(",\n\"message\": \"").length());
    pos = data.find(seperator);
    name = data.substr(0, pos);
    data.erase(0, pos + seperator.length());
    pos = data.find(seperator);
    dat = data.substr(0, pos);
    data.erase(0, pos + seperator.length());
    timePerQuestion = atoi(dat.c_str());
    pos = data.find("\n}");
    dat = data.substr(0, pos);
    NumOfPlayers = atoi(dat.c_str());
    r._name = name;
    r._maxPlayerCount = NumOfPlayers;
    r._questionTime = timePerQuestion;
    r._questionCount = 10;
    r._status = "active";
    Room ro(r);
    ro.addUser(u.Username);
    ro.addUser(u);
    RoomManager::_rooms.insert({ name,ro });
}

std::vector<Room> MenuRequestHandler::getRooms(std::string data)
{
    std::vector<Room> rooms;
    for (const auto& kvp : RoomManager::_rooms) 
    {
        rooms.push_back(kvp.second);
    }
    return rooms;
}

std::string MenuRequestHandler::getPlayersInRoom(std::string data)
{
    return std::string();
}

void MenuRequestHandler::joinRoom(std::string data, SOCKET s)
{
    std::vector<Room> rooms = getRooms(data);
    int i = 0;
    i = rooms.size();
    std::string message ="{\n\"type\": 1,\n\"Message\": \"" + std::to_string(i) + "\"\n}";
    bool a = Communicator::Send(message, s);
    rooms = getRooms(data);
    for (int j = 0; j < i; j++)
    {
        message = "{\n\"RoomName\": \"" + rooms.at(j).getData()._name + "\",\n\"TimePerQuestion\": " + std::to_string(rooms.at(j).getData()._questionTime) + ",\n\"NumberOfPlayers\": \"" + std::to_string(rooms.at(j).getData()._maxPlayerCount) + "\",\n\"ingame\": [\n";
        for (int k = 0; k < rooms.at(j).users.size(); k++)
        {
            message += "\"Username\": \"" + rooms.at(j).users.at(k).Username + "\",\n\"Password\": \"" + rooms.at(j).users.at(k).Password + "\",\n\"Email: \"" + rooms.at(j).users.at(k).Email + "\",\n";
            if (k + 1 == rooms.at(j).users.size())
            {
                message += "\"Username\": \"" + rooms.at(j).users.at(k).Username + "\",\n\"Password\": \"" + rooms.at(j).users.at(k).Password + "\",\n\"Email: \"" + rooms.at(j).users.at(k).Email + "\"\n],\n";
            }
        }
        message += "\"started\": false";
        Communicator::Send(message, s);
    }
}

void MenuRequestHandler::getStatistics(std::string data, SOCKET s)
{

}

void MenuRequestHandler::getHighScore(std::string data, SOCKET s)
{
}

void MenuRequestHandler::logout(std::string data)
{
}
