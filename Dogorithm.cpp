#include "Dogorithm.h"
#include "Users.h"
#include<iostream>
using namespace std;

void Dogorithm::registerUser(Users user) {
    users->push_back(user);
    std::cout << user.getName() << " joined Dogorithm chat room!" << std::endl;
}

void Dogorithm::removeUser(Users user) {
    for (size_t i = 0; i < users->size(); i++) {
        if ((*users)[i] == user) {
            users->erase(users->begin() + i);
            std::cout << user.getName() << " left Dogorithm chat room!" << std::endl;
            return;
        }
    }
}

void Dogorithm::sendMessage(string message, Users fromUser){
    if(hasUser(fromUser)){
        cout<<"New message from "<<fromUser.getName()<<endl;
        chatHistory->push_back(message);
    }
    else{
        cout<<"Cannot send a message to this chatRoom!\n";
    }
}

void Dogorithm::saveMessage(string message, Users fromUser){
    if(hasUser(fromUser)){
        cout<<fromUser.getName()<<" just sent a message!\n";
        chatHistory->push_back(message);
    }
    else{
        cout<<"Cannot save this message!\n";
    }
}