#include "LoginManager.h"
#include <iostream>
#include <regex>

using std::string;
using std::shared_ptr;

using std::regex_match;



LoginManager::LoginManager(shared_ptr<SqliteDatabase>& database) : _database(database)
{

}
LoginManager::LoginManager(shared_ptr<IDatabase>& database) : _Idatabase(database)
{

}



void LoginManager::signup(const SignupRequest& signupRequest)
{

	isInputValid(signupRequest);

	if (!_database->doesUsernameExist(signupRequest._username))
	{
		//display error;
	}

	// add new user to database & _loggedUsers list
	_database->createUser(signupRequest._username,
	signupRequest._password,
	signupRequest._email);

}



void LoginManager::login(const LoginRequest& loginRequest)
{

	if (!_database->checkPassword(loginRequest._username, loginRequest._password))
	{
		//display error;
	}
		
	if (!_loggedUsers.insert(loginRequest._username).second)
	{
		//display error;
	}
	if (!_database->doesUsernameExist(loginRequest._username))
	{
		//send to GUI user doesnt exist
	}
}



void LoginManager::logout(const string& name)
{

	if (!_loggedUsers.erase(name))
	{
		//display error;
	}

}



void LoginManager::isInputValid(const SignupRequest& input)
{

	string err = "";

	if (!isPasswordValid(input._password))
	{
		err = "password is invalid, must constain: 8+ chars 1+ number, uppercase, lowercase and unique";
	}

	else if (input._username == "")
	{
		err = "username can't be empty";
	}

	else if (!isEmailValid(input._email))
	{
		err = "email is invalid, must be in a regular email format";
	}
	
	else if (_database->doesUsernameExist(input._username))
	{
		err = "Username Already Exists";
	}


	if (!err.empty())
	{
		//display error;
	}

}


bool LoginManager::isPasswordValid(const string& password)
{

	//password must contain 8 characters and at least one number, one letter, and one unique symbol;
	std::regex regex(R"((?=.*\d.*)(?=.*[a-zA-Z].*)(?=.*[\!\@\#\$\%\^\&\*].*).{8,})");

	return regex_match(password, regex);
}


bool LoginManager::isEmailValid(const string& email)
{
	std::regex regex(R"([a-zA-Z0-9]+@[a-zA-Z0-9]+[.][a-zA-Z0-9]+([.][a-zA-Z0-9]+)?)");
	
	return regex_match(email, regex);
}
