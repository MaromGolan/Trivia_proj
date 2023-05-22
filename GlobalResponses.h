#pragma once

struct GoodResponse
{
	std::string _ok = "ok";
};

struct BadResponse
{
	std::string _error;
};