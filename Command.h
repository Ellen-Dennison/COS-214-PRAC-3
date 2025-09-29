#ifndef COMMAND
#define COMMAND

#include <iostream>
#include <vector>
#include "ChatRoom.h"
#include "Users.h"

class Command
{
    protected:
    ChatRoom *room;
    std::string message;
    Users fromUser;
    
    public:
    virtual void execute() = 0;
};

#endif