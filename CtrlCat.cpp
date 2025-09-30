#include "CtrlCat.h"
#include "Users.h"
#include <iostream>

CtrlCat::CtrlCat() : ChatRoom() {}

CtrlCat::~CtrlCat() {}

void CtrlCat::registerUser(Users* user) {
    if (!hasUser(user)) {
        users->push_back(user);
        std::cout << user->getName() << " joined by CtrlCat chat room!" << std::endl;
    }
}

void CtrlCat::removeUser(Users* user) {
    for (size_t i = 0; i < users->size(); i++) {
        if ((*users)[i] == user) {
            users->erase(users->begin() + i);
            std::cout << user->getName() << " left CtrlCat chat room!" << std::endl;
            return;
        }
    }
}

void CtrlCat::sendMessage(string message, Users* fromUser) {
    std::cout << "[CtrlCat] " << fromUser->getName() << ": " << message << std::endl;
    
    for (size_t i = 0; i < users->size(); i++) {
        if ((*users)[i] != fromUser) {  // Don't send to self
            (*users)[i]->receive(message, *fromUser, this);
        }
    }
}

void CtrlCat::saveMessage(string message, Users* fromUser) {
    string fullMessage = fromUser->getName() + ": " + message;
    chatHistory->push_back(fullMessage);
    std::cout << "[CtrlCat] Message saved to history" << std::endl;
}


Iterator* CtrlCat::createIterator()
{
  return new UserIterator(users);
}