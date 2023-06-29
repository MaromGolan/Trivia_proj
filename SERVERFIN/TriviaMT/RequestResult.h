#pragma once

#include <string>
#include "IRequestHandler.h"
#include <memory>

class IRequestHandler;

using JsonBase::Buffer;


struct RequestResult 
{
	
	std::string _response;
	std::shared_ptr<IRequestHandler> _newHandler;
	
};