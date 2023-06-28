#pragma once

#include "structs.h"
#include "SqliteDatabase.h"

#include <memory>
#include <set>


class LoginManager
{
	
public:


	// methods for singleton
	LoginManager(std::shared_ptr<SqliteDatabase>& database);
	LoginManager(std::shared_ptr<IDatabase>& database);

	~LoginManager() = default;

	LoginManager(const LoginManager&) = delete;
	LoginManager& operator=(const LoginManager&) = delete;

	static LoginManager& getInstance(std::shared_ptr<IDatabase>& database)
	{
		static LoginManager instance(database);

		return instance;
	}


	// Methods
	void signup(const SignupRequest& signupRequest);
	void login (const LoginRequest& loginRequest);
	void logout(const std::string& name);



private:


	// Constructors


	// Input Validation Methods
	void isInputValid(const SignupRequest& input);
	
	bool isPasswordValid(const std::string& password);
	bool isEmailValid(const std::string& email);


	// Fields
	std::set<std::string> _loggedUsers;
	std::shared_ptr<SqliteDatabase> _database;
	std::shared_ptr<IDatabase> _Idatabase;


};

