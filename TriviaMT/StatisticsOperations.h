#pragma once

#include <string>
#include <map>


struct Stats
{
	float _timeForAnswer;
	int _rightAnswers;
	int _wrongAnswers;
	int _gamesPlayed;
};


struct getHighScore
{
	std::multimap<int, std::string> _statistics;
};


struct getPersonalStats
{
	Stats _statistics;
};