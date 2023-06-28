#include <iostream>
#include <string>
#include <vector>

class User
{
public:

    User(const std::string& u, const std::string& p, const std::string& e);
    User();

    std::string Username;
    std::string Password;
    std::string Email;

    int getCorrectAnswerCount() const;
    int getWrongAnswerCount() const;
    int getAverageAnswerTime() const;

    void setCorrectAnswerCount(int newVal);
    void setWrongAnswerCount(int newVal);
    void setAverageAnswerTime(int newVal);


private:


    int correct_answer_count;
    int wrong_answer_count;
    int average_answer_time;

};

