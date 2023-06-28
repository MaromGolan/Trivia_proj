#include "User.h"


User::User(const std::string& u, const std::string& p, const std::string& e): Username(u), Password(p), Email(e)
{

}

User::User() 
{
}



int User::getCorrectAnswerCount() const
{
	return correct_answer_count;
}

int User::getWrongAnswerCount() const
{
	return wrong_answer_count;
}

int User::getAverageAnswerTime() const
{
	return average_answer_time;
}

void User::setCorrectAnswerCount(int newVal)
{
	correct_answer_count = newVal;
}

void User::setWrongAnswerCount(int newVal)
{
	wrong_answer_count = newVal;
}

void User::setAverageAnswerTime(int newVal)
{
	average_answer_time = newVal;
}