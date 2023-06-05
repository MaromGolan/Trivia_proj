#pragma once

#include "Structs.h"
#include "IDataBase.h"
#include "sqlite3.h"
#include <sstream>


class SQLDatabase : public IDatabase
{

public:

	//Constructor and destructor;
	SQLDatabase();
	virtual ~SQLDatabase() = default;

private: 
	
	bool openDatabase();
	void initializeDB();
	
	
	sqlite3* _db;

};

