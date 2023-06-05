#pragma once

#include "Structs.h"

#include <string>
#include <map>
#include <set>

class IDatabase
{

public:
	
	IDatabase() = default;
	virtual ~IDatabase() = default;

	virtual std::set<TriviaQuestion> getQuestions(const int& numOfQuestions) = 0;
	

	const std::string DB_NAME = "TriviaDB";


	// questions Table
	const std::string QUESTIONS_TABLE = "questions";
	const std::string QUESTION_COLUMN = "question";
	const std::string OPTIONS_COLUMN = "options";
	const std::string RIGHT_ANSWERS_COLUMN = "correct_answers";

};
