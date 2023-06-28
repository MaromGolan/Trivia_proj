#pragma once
#include "IDataBase.h"
#include "Communicator.h"
#include "IRequestHandler.h"

class Server
{

private:

    IDatabase& m_database;
    Communicator m_communicator;
    //RequestHandlerFactory m_handlerFactory; doesnt matter right now

public:
    static void run(); 
};

