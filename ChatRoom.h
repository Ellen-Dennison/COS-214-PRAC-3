#ifndef CHATROOM_H
#define CHATROOM_H
#include "Users.h"
#include<string>

class ChatRoom{
    private:
            Users* users;
            std::string* chatHistory;
    public:
            virtual void registerUser(Users user) = 0;
            virtual void sendMessage(std::string message, Users fromUser) = 0;
            virtual void saveMessage(string message, Users user) = 0;
            virtual void removeUser(Users user) = 0;
};

#endif