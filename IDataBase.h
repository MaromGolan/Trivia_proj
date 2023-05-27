#pragma once
#include <iostream>
#include <string>
#include "Question.h"
#include <list>
class IDataBase
{


public:
	virtual bool doesUserExists(std::string user);
	virtual bool doesPasswordMatch(std::string pass, std::string check);
	virtual void addNewUser(std::string un, std::string pass, std::string em);
	virtual std::list<Question> getQuestions(int numQuestion);
	virtual int getPlayerAverageAnswers(std::string user);
	virtual int getNumOfCorrectAnswers(std::string user);
	virtual int getNumOfTotalAnswers(std::string user);
	virtual int getNumOfPlayerGames(std::string user);
	virtual void getSecurityKey(std::string user);
};