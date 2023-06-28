#include "GameManager.h"

GameManager::GameManager()
{

}

GameManager::~GameManager()
{

}

void GameManager::InsertNewUser(User newUser, SOCKET newSocket)
{

	std::pair<User, SOCKET> newAddition;

	newAddition.first = newUser;
	newAddition.second = newSocket;

	_users.insert(newAddition);

}