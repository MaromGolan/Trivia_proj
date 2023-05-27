#pragma once

#include <iostream>
#include <ctime>
#include <vector>

typedef unsigned char Byte;

struct RequestInfo
{
    int RequestId;
    std::time_t currentTime;
    std::vector<Byte> buffer;
}typedef RequestInfo;

struct RequestResult
{
    std::vector<Byte> response;
    IRequestHandler* newHandler;
}typedef RequestInfo;


class IRequestHandler
{
public:
	virtual bool isRequestRelevent(RequestInfo i);
    virtual RequestResult handleRequest(RequestInfo i);
};

