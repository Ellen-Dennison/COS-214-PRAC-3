#ifndef COMMAND_H
#define COMMAND_H
#include "ChatRoom.h"
#include "Users.h"
#include<string>

class Command{
    protected:
             ChatRoom room;
             std::string message;
             Users fromUser;
    public:
            virtual void execute() = 0;
};
#endif