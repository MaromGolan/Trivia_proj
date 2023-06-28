#pragma once
#include "IDatabase.h"
#include "SqliteDatabase.h"
#include "Room.h"
#include <vector>
#include "Structs.h"

class GameManager
{
public:

	GameManager();
	~GameManager();

	void InsertNewUser(User newUser, SOCKET newSocket);

	std::unordered_map<User, SOCKET> _users;
	

private:




};