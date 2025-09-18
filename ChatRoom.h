#ifndef CHATROOM 
#define CHATROOM

#include <iostream>
#include <vector>
#include "Command.h"
#include "Users.h"


class ChatRoom
{
    private:
    Users* users;
    std::string chatHistory;

    public:
    void registerUser(Users user);
    void sendMessage(std::string message, Users fromUser);
    void saveMessage(std::string message, Users fromUser);
    void removeUser(Users user);
    
};

#endif