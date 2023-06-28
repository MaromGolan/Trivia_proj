#pragma once

#include "RequestInfo.h"

typedef unsigned char Byte;

#include "RequestResult.h"


class IRequestHandler
{
public:

    virtual bool isRequestRelevant(const RequestInfo request) = 0;
    virtual RequestResult handleRequest(const RequestInfo& requestInfo) = 0;
};


