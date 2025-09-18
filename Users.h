#ifndef USERS
#define USERS

#include <iostream>
#include "Command.h"
#include "ChatRoom.h"

class Users
{
    private:
    ChatRoom* chatRooms;
    std::string name;
    Command* commandQueue;

    public:
    void send(std::string message,  ChatRoom room);
    void receive(std::string message, Users fromUser, ChatRoom room);
    void addCommand(Command command);
    void executeAll();
};

#endif