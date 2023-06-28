#include "GameRequestHandler.h"
#include "Room.h"
#include "RoomManager.h"
#include "JsonBase.h"
#include "Communicator.h"


GameRequestHandler::GameRequestHandler(Room room, User user)
{
	this->_room = new Room(room.getData());
	this->_user = &user;
}


GameRequestHandler::~GameRequestHandler()
{
	delete _room;
	delete _user;
}

bool GameRequestHandler::isRequestRelevant(RequestInfo request)
{
	//no need to implement this function;
}


std::string GameRequestHandler::LeaveGameRequest(std::string request, SOCKET s)
{
	//here I need you to use GameManager, and delete the Room if the player that wants to leave is the admin, and remove the player from the room, instead;
}

std::string GameRequestHandler::GetQuestionRequest(std::string request, SOCKET s)
{
	//Marom here too;
}

std::string GameRequestHandler::SubmitAnswerRequest(std::string request, SOCKET s)
{
	//implemented into the GUI;
}

std::string GameRequestHandler::GetGameResultRequest(std::string request, SOCKET s)
{
	int max = 0;
	std::string winner = "";

	for (auto& player : _manager._users)
	{
		if (player.first.getCorrectAnswerCount() > max)
		{
			max = player.first.getCorrectAnswerCount();
			winner = player.first.Username;
		}
	}

	return winner;

}
