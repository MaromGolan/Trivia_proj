#pragma once

#include <string>

struct LoginRequest
{
	std::string _username;
	std::string _password;
};



struct SignupRequest
{
	std::string _username;
	std::string _password;
	std::string _email;
	std::string _phone;
	std::string	_date;

};
