#include "SqliteDataBase.h"


SqliteDatabase::SqliteDatabase(const std::string& filename)
{
    int rc = sqlite3_open(filename.c_str(), &this->db);
    if (rc) 
    {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
    }
}

void SqliteDatabase::openDatabase(sqlite3* db, std::string filename)
{
    int rc = sqlite3_open(filename.c_str(), &db);
    if (rc)
    {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
    }
}

SqliteDatabase::~SqliteDatabase()
{
    sqlite3_close(this->db);
}

bool SqliteDatabase::createUser(const std::string& username, const std::string& password, const std::string& email) {
    std::string query = "INSERT INTO users (username, password, email) VALUES ('" + username + "', '" + password + "', '" + email + "');";
    char* errorMessage;
    int rc = sqlite3_exec(db, query.c_str(), 0, 0, &errorMessage);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errorMessage << std::endl;
        sqlite3_free(errorMessage);
        return false;
    }
    std::cout << "User created successfully!" << std::endl;
    return true;
}

bool SqliteDatabase::doesUsernameExist(const std::string& username) {
    std::string query = "SELECT COUNT(*) FROM users WHERE username = '" + username + "';";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(this->db, query.c_str(), -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(this->db) << std::endl;
        sqlite3_finalize(stmt);
        return false;
    }
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        int count = sqlite3_column_int(stmt, 0);
        sqlite3_finalize(stmt);
        return count > 0;
    }
    sqlite3_finalize(stmt);
    return false;
}

bool SqliteDatabase::checkPassword(const std::string& username, const std::string& password) {
    std::string query = "SELECT COUNT(*) FROM users WHERE username = '" + username + "' AND password = '" + password + "';";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(this->db, query.c_str(), -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(this->db) << std::endl;
        sqlite3_finalize(stmt);
        return false;
    }
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        int count = sqlite3_column_int(stmt, 0);
        sqlite3_finalize(stmt);
        return count > 0;
    }
    sqlite3_finalize(stmt);
    return false;
}

std::string SqliteDatabase::userStats(std::string username, sqlite3* db)
{
    std::string query = "SELECT AmountOfQuestions, AmountOfCorrectAnswers, AmountOfWrongAnswers "
        "FROM STATISTICS "
        "WHERE Username = '" + username + "';";

    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(this->db, query.c_str(), -1, &stmt, nullptr);
    
    rc = sqlite3_step(stmt);
    std::string json;
    if (rc == SQLITE_ROW)
    {
        int amountOfQuestions = sqlite3_column_int(stmt, 0);
        int amountOfCorrectAnswers = sqlite3_column_int(stmt, 1);
        int amountOfWrongAnswers = sqlite3_column_int(stmt, 2);
        json = "{\n\"type\": 6,\n\"message\": \"";
        json += std::to_string(amountOfQuestions) + "," + std::to_string(amountOfCorrectAnswers) + "," + std::to_string(amountOfWrongAnswers) + "\n}";
    }
    sqlite3_finalize(stmt);
    return json;
}

std::string SqliteDatabase::top5stats(sqlite3* db)
{
    std::string query = "SELECT Username "
        "FROM STATISTICS "
        "ORDER BY AmountOfCorrectAnswers DESC "
        "LIMIT 5;";

    sqlite3_stmt* stmt;
   int rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to execute query: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
    }

    // Build the JSON array
    std::string jsonMessage = "{\n\"type\": 7,\n\"message\": \"";
    int i = 1;
    while (sqlite3_step(stmt) == SQLITE_ROW) 
    {
        std::string username = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));

        // Add username to the JSON array
        jsonMessage += std::to_string(i) +": " + username;
        i++;
    }
    jsonMessage += "\n}";
    sqlite3_finalize(stmt);
    return jsonMessage;
}

std::string SqliteDatabase::emailOfUser(std::string username, sqlite3* db)
{
    
    std::string email;
    std::string query = "SELECT Email FROM USERS WHERE USERNAME = ?";
    sqlite3_stmt* statement;
    int rc = sqlite3_prepare_v2(db, query.c_str(), -1, &statement, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Cannot prepare statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(statement);
        sqlite3_close(db);
        return email;
    }

    sqlite3_bind_text(statement, 1, username.c_str(), -1, SQLITE_STATIC);

    rc = sqlite3_step(statement);
    if (rc == SQLITE_ROW) {
        const unsigned char* emailResult = sqlite3_column_text(statement, 0);
        email = reinterpret_cast<const char*>(emailResult);
    }
    sqlite3_finalize(statement);
    return email;
}
    
    