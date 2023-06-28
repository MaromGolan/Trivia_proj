#pragma once

#include <vector>
#include "json.hpp"

using json = nlohmann::json;


namespace JsonBase
{
	typedef std::vector<char> Buffer;

	const std::string CODE = "00000000";
	const int SIZE = 8;
	const int LENGTH = 32;
}