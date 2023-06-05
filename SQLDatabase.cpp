#include "SQLDatabase"
SQLDatabase::SQLDatabase()
{
    int rc = sqlite3_open("STATISTICS.db", &sdb);
    int rc = sqlite3_open("USERS.db", &udb);
}
void addUser(std::string username, std::string password, std::string email)
{
    std::string query = "INSERT INTO USERS (Username, Password, Email) VALUES (?, ?, ?)";
    sqlite3_stmt* statement;
    rc = sqlite3_prepare_v2(db, query.c_str(), -1, &statement, nullptr);
    sqlite3_bind_text(statement, 1, username.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(statement, 2, password.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(statement, 3, email.c_str(), -1, SQLITE_STATIC);
}
	
void addCorrect(std::string username)
{
    std::string query = "UPDATE STATS SET CORRECT_ANSWERS = CORRECT_ANSWERS + 1 WHERE USERNAME = ?";
    sqlite3_stmt* statement;
    rc = sqlite3_prepare_v2(db, query.c_str(), -1, &statement, nullptr);
    sqlite3_bind_text(statement, 1, username.c_str(), -1, SQLITE_STATIC);
}
void addWrong(std::string username)
{
    std::string query = "UPDATE STATS SET WRONG_ANSWERS = WRONG_ANSWERS + 1 WHERE USERNAME = ?";
    sqlite3_stmt* statement;
    rc = sqlite3_prepare_v2(db, query.c_str(), -1, &statement, nullptr);
    sqlite3_bind_text(statement, 1, username.c_str(), -1, SQLITE_STATIC);
}

void getStats(std::string username)
{
    std::string query = "SELECT CORRECT_ANSWERS, WRONG_ANSWERS FROM USERS WHERE USERNAME = ?";
    sqlite3_stmt* statement;
    rc = sqlite3_prepare_v2(db, query.c_str(), -1, &statement, nullptr);
    sqlite3_bind_text(statement, 1, username.c_str(), -1, SQLITE_STATIC);
    std::cout << "Correct Answers: " << correctAnswers << std::endl;
    std::cout << "Wrong Answers: " << wrongAnswers << std::endl;

}
