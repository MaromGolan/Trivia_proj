

#include <iostream>
#include <fstream>
#include <algorithm>
#include <Windows.h>
#include "MessageSender.h"


MessagesSender::MessagesSender()
{
}

MessagesSender::~MessagesSender()
{
}

void MessagesSender::showMenu()
{
	// Clean the screen.
	system("cls");
	std::cout << "1. Signin\n2. Signout\n3. Connected Users\n4. exit" << std::endl;
	short choice;
	std::cin >> choice;

	switch (choice) 
	{
		case 1: 
			enterUser();
			break;
		case 2: 
			removeUser();
			break;
		case 3: 
			showUsers();
			break;
		case 4: exit(0);
			break;
	}
}

void MessagesSender::enterUser()
{
	std::cout << "Please enter a user name: " << std::endl;
	std::string name;
	std::cin >> name;

	if (!exists(name)) 
	{
		std::unique_lock<std::mutex> lck(_mUsers);
		_users.push_back(name);
		lck.unlock();
		std::cout << "User added successfully! username=" << name << std::endl;
	}
	else
	{
		std::cout << "User already exists!" << std::endl;
	}

	system("PAUSE");
}

void MessagesSender::removeUser()
{
	std::cout << "Please enter a user name: " << std::endl;
	std::string name;
	std::cin >> name;


	if (exists(name)) 
	{
		std::unique_lock<std::mutex> lck(_mUsers);
		_users.erase(std::remove(_users.begin(), _users.end(), name), _users.end());
		lck.unlock();
		std::cout << "User removed successfully! username=" << name << std::endl;
	}
	else
	{
		std::cout << "User doesn't exist!" << std::endl;
	}

	system("PAUSE");
}

void MessagesSender::showUsers()
{
	std::unique_lock<std::mutex> lckUsers(_mUsers);

	for (int i = 0; i < _users.size(); ++i) 
	{
		std::cout << _users[i] << std::endl;
	}
	lckUsers.unlock();

	system("PAUSE");
}

bool MessagesSender::exists(const std::string & name)
{
	std::unique_lock<std::mutex> lckUsers(_mUsers);
	for (int i = 0; i < _users.size(); ++i)
	{
		if (name == _users[i]) 
		{
			lckUsers.unlock();
			return true;
		}
	}

	lckUsers.unlock();
	return false;
}

void MessagesSender::readFileForMessages()
{
	while (true) 
	{
		// Read the data.
		std::ifstream dataF(DATA_FILE_PATH, std::ios::in);
		std::string line;
		bool dataEntered = false;

		while (std::getline(dataF, line)) 
		{
			std::unique_lock<std::mutex> lck(_mMessages);
			_messages.push(line);
			lck.unlock();
			dataEntered = true;
		}
		if (dataEntered) 
		{
			_cvMessages.notify_all();
		}
		dataF.close();

		// Clean the file.
		std::ofstream file(DATA_FILE_PATH, std::ofstream::out | std::ofstream::trunc);
		file.close();

		Sleep(READ_DATA_SLEEP_INTERVAL);
	}
}

void MessagesSender::sendMessages()
{
	std::unique_lock<std::mutex> lckUsers(_mUsers, std::defer_lock);
	while (true)
	{

		std::unique_lock<std::mutex> lckMessages(_mMessages);
		if (_messages.empty())
			_cvMessages.wait(lckMessages);


		lckMessages.unlock();

		std::ofstream file(OUTPUT_FILE_PATH, std::ios::out | std::ios::app);	

		int i;
		std::string msg;

		// _messages is shared queue
		lckMessages.lock();
		while (!_messages.empty())
		{
			msg = _messages.front();
			_messages.pop();
			lckMessages.unlock();
			
			lckUsers.lock();
			for (i = 0; i < _users.size(); ++i) 
			{
					file << _users[i] << ": " << msg << std::endl;
			}
			lckUsers.unlock();

			lckMessages.lock();
		}

		lckMessages.unlock();
		file.close();
	}
}

