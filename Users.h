#ifndef USERS_H
#define USERS_H
#include "Command.h"
#include<string>

class Users{
    protected:
              ChatRoom* chatRooms;
              std::string name;
              Command* commandQueue;
    public:
             void send(std::string message, ChatRoom room);
             void receive(std::string message, Users fromUser, ChatRoom room);
             void addCommand(Command command);
             void executeAll();
};
#endif