#pragma once

#include "Structs.h"
#include "IDataBase.h"
#include "sqlite3.h"
#include <sstream>
#include <iostream>
#include <string>

class SQLDatabase : public IDatabase
{

public:

	//Constructor and destructor;
	SQLDatabase();
	virtual ~SQLDatabase() = default;
	void addUser(std::string username, std::string password, std::string email);
	void addCorrect(std::string username);
	void addWrong(std::string username);
	void getStats(std::string username);

private: 
	
	bool openDatabase();
	void initializeDB();
	
	
	sqlite3* udb;
	sqlite3* sdb;

};

