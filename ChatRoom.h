#ifndef CHATROOM_H
#define CHATROOM_H
#include<string>
#include<vector>
using namespace std;

class Users;

class ChatRoom{
    protected:
        std::vector<Users*>* users;         // Changed to Users* (pointers)
        std::vector<string>* chatHistory;
    public:
        ChatRoom();
        virtual ~ChatRoom();
        
        virtual void registerUser(Users* user) = 0;      // Changed to Users*
        virtual void removeUser(Users* user) = 0;        // Changed to Users*
        virtual void sendMessage(string message, Users* fromUser) = 0;    // Changed to Users*
        virtual void saveMessage(string message, Users* fromUser) = 0;    // Changed to Users*
        
        const std::vector<Users*>& getUsers();           // Changed return type
        const std::vector<std::string>& getChatHistory();
        size_t getUserCount();
        size_t getMessageCount();
        bool hasUser(Users* user);                       // Changed to Users*
};
#endif