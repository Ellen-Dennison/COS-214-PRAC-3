#include "ChatRoom.h"
using namespace std;
#include<string>

ChatRoom::ChatRoom(){
    users = new std::vector<Users>();
    chatHistory = new std::vector<string>();
}

ChatRoom::~ChatRoom(){
    delete users;
    delete chatHistory;
}

const std::vector<Users>& ChatRoom::getUsers(){
    return *users;
}

const std::vector<std::string>& ChatRoom::getChatHistory(){
    return *chatHistory;
}

size_t ChatRoom::getUserCount(){
    return users->size();
}

size_t ChatRoom::getMessageCount(){ 
    return chatHistory->size();
}

bool ChatRoom::hasUser(Users user){
    for (size_t i = 0; i < users->size(); i++) {
        if ((*users)[i] == user) {
            return true;
        }
    }
    return false;
}
