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
	std::unordered_map<User, gamestats> usersgamestats;
};

class gamestats
{
public:
	std::string currQuestion;
	int correct_answer_count;
	int wrong_answer_count;
	int average_answer_time;
	bool finished;
};