#pragma once

#include <vector>
#include "json.hpp"

using json = nlohmann::json;


namespace JsonBase
{
	typedef std::vector<char> Buffer;

	const std::string CODE = "";

	const int BYTE = 8;
	const int DATA_LENGTH = 32;

}