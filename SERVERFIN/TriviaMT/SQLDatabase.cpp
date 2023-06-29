#include "SqliteDatabase.h"
#include "SqliteException.h"
#include  <io.h>


using std::string;
using std::stringstream;



//? Constructors ?//


/* -- C'tor -- */
SqliteDatabase::SqliteDatabase() : 
	_db(nullptr)
{
		
	// before openning/creating Database, find if the db file exist
	bool isDBAlreadyExist = !_access(string(DB_NAME + ".sqlite").c_str(), 0);
	
	if (!openDatabase())
		throw SqliteException("Can't create/connet to sqlite database");

	if (!isDBAlreadyExist)
		initializeDB();

}


//? Methods ?//


/* 
	-- find if the use exists or not by username --
	* input: user's username
	* output: exists or not
*/
bool SqliteDatabase::doesUserExists(const string& username)
{

	stringstream sql;
	bool exists = false;

	sql << "SELECT COUNT() FROM " << USERS_TABLE << " WHERE "
		<< USER_NAME_COLUMN << " = '" << username << "';";

	sqliteRequest(sql, booleanCallback, &exists);

	return exists;

}

/*
	-- find if the given password match the real password of the user --
	* input: username, password
	* output: bool: password match or not
*/
bool SqliteDatabase::doesPasswordMatch(const string& username,
	const string& password)
{

	stringstream sql;
	bool match = false;

	sql << "SELECT COUNT() FROM " << USERS_TABLE << " WHERE "
		<< USER_NAME_COLUMN << " = '" << username << "' AND "
		<< PASSWORD_COLUMN << " = '" << password << "';";
	
	sqliteRequest(sql, booleanCallback, &match);

	return match;

}


/*
	-- add user to USERS_TABLE --
	* input: user's data: name, password, email, etc...
*/
void SqliteDatabase::addNewUser(const string& name, const string& password,
	const string& email, const Address& address, const string& phone,
	const string& date)
{

	stringstream sql;
	
	sql << "INSERT INTO " << USERS_TABLE << " ( "
		<< USER_NAME_COLUMN << ", " << PASSWORD_COLUMN << ", " 
		<< EMAIL_COLUMN << ", " << CITY_COLUMN << ", " << STREET_COLUMN << ", " 
		<< APT_COLUMN << ", " << PHONE_COLUMN << ", " << DATE_COLUMN 
		<< " ) VALUES ( '" 
		<< name << "', '" << password << "', '" << email << "', '" 
		<< address._city  << "', '" << address._street << "', '" 
		<< address._apt << "', '" << phone << "', '" << date << "' );";

	sqliteRequest(sql);

}



//? Private Methods ?//


/*
	-- try openning the database --
	* input:
*/
bool SqliteDatabase::openDatabase()
{
	return !sqlite3_open(string(DB_NAME + ".sqlite").c_str(), &_db);
}

/* -- initialize Database - create new USER_TABLE -- */
void SqliteDatabase::initializeDB()
{
	
	stringstream sql;

	sql << "CREATE TABLE " << USERS_TABLE << " ( "
		<< USER_NAME_COLUMN << " TEXT PRIMARY KEY NOT NULL, "
		<< PASSWORD_COLUMN << " TEXT NOT NULL, "
		<< EMAIL_COLUMN << " TEXT NOT NULL, "
		<< CITY_COLUMN << " TEXT NOT NULL, "
		<< STREET_COLUMN << " TEXT NOT NULL, "
		<< PHONE_COLUMN << " TEXT NOT NULL, "
		<< DATE_COLUMN << " TEXT NOT NULL );";
	
	sqliteRequest(sql);

}



/*
   -- execute sql request --
   * input: sql command stringstream, callback function,
			data to pass to callback function
*/
void SqliteDatabase::sqliteRequest(const stringstream& sql,
	int(*callback)(void*, int, char**, char**), void* data)
{
	sqliteRequest(sql.str().c_str(), callback, data);
}

/*
  -- execute sql request --
  * input: sql command, callback function,
   data to pass to callback function
*/
void SqliteDatabase::sqliteRequest(const char* sql,
	int(*callback)(void*, int, char**, char**), void* data)
{
	char* errMsg = nullptr;
	if (sqlite3_exec(_db, sql, callback, data, &errMsg))
		throw SqliteException(errMsg);
}


/* Sqlite Boolean callback Function */
int SqliteDatabase::booleanCallback(void* boolean, int len, char** data, char** columnName)
{
	bool* b = static_cast<bool*>(boolean);

	*b = atoi(data[0]);
	
	return 0;
}
