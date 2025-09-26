#ifndef CHATROOM_H
#define CHATROOM_H
#include "Users.h"
#include<string>
using namespace std;
#include<vector>

class Users;
class ChatRoom{
    protected:
            std::vector<Users>* users;//pointer to vector of Users objects
            std::vector<std::string>* chatHistory; //pointer to vector of strings
    public:
            virtual void registerUser(Users user) = 0;
            virtual void removeUser(Users user) = 0;
            ChatRoom();
            virtual ~ChatRoom();

            //getters for testing/demo purposes
            const std::vector<Users>& getUsers();
            const std::vector<std::string>& getChatHistory();
            size_t getUserCount();
            size_t getMessageCount();
            bool hasUser(Users user);
            virtual void sendMessage(string message, Users toUser) = 0;
            virtual void saveMessage(string message, Users fromUser) = 0;
};

#endif