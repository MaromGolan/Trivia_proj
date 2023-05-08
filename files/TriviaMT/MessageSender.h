#pragma once

#include <mutex>
#include <vector>
#include <queue>
#include <string>
#include <condition_variable>



const std::string DATA_FILE_PATH = "data.txt";
const unsigned int READ_DATA_SLEEP_INTERVAL = 30 * 1000;
const std::string OUTPUT_FILE_PATH = "output.txt";


class MessagesSender
{
public:
	MessagesSender();
	~MessagesSender();

	void showMenu();
	void readFileForMessages();
	void sendMessages();

private:
	// Menu related.
	void enterUser();
	void removeUser();
	void showUsers();

	// Checks if a user exists.
	bool exists(const std::string & name);

	std::vector<std::string> _users;
	std::mutex _mUsers;
	std::mutex _mMessages;
	std::condition_variable _cvMessages;

	std::queue<std::string> _messages;

	
};

