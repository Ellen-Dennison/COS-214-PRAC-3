#include "Dogorithm.h"
#include "Users.h"
#include <iostream>

Dogorithm::Dogorithm() : ChatRoom() {}

Dogorithm::~Dogorithm() {}

void Dogorithm::registerUser(Users* user) {
    if (!hasUser(user)) {
        users->push_back(user);
        std::cout << user->getName() << " joined Dogorithm chat room!" << std::endl;
    }
}

void Dogorithm::removeUser(Users* user) {
    for (size_t i = 0; i < users->size(); i++) {
        if ((*users)[i] == user) {
            users->erase(users->begin() + i);
            std::cout << user->getName() << " left Dogorithm chat room!" << std::endl;
            return;
        }
    }
}

void Dogorithm::sendMessage(string message, Users* fromUser) {
    std::cout << "[Dogorithm] " << fromUser->getName() << ": " << message << std::endl;
    
    for (size_t i = 0; i < users->size(); i++) {
        if ((*users)[i] != fromUser) {  // Don't send to self
            (*users)[i]->receive(message, *fromUser, this);
        }
    }
}

void Dogorithm::saveMessage(string message, Users* fromUser) {
    string fullMessage = fromUser->getName() + ": " + message;
    chatHistory->push_back(fullMessage);
    std::cout << "[Dogorithm] Message saved to history" << std::endl;
}