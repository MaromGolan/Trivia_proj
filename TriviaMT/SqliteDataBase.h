#pragma once
#include <iostream>
#include "sqlite3.h"
#include "IDataBase.h"
#include <string>
#include "Communicator.h"

class SqliteDatabase 
{
private:
    sqlite3* db;

public:
    SqliteDatabase(const std::string& filename);
    ~SqliteDatabase();
    bool createUser(const std::string& username, const std::string& password, const std::string& email);
    bool doesUsernameExist(const std::string& username);
    bool checkPassword(const std::string& username, const std::string& password);
    static std::string emailOfUser(std::string username, sqlite3* db);
    static void openDatabase(sqlite3* db, std::string filename);

};

/*
    Database db("mydatabase.db");
    db.createUser("john_doe", "password123", "john.doe@example.com");
    return 0;
*/
