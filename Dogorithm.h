#ifndef DOGORITHM_H
#define DOGORITHM_H
#include "ChatRoom.h"
#include<string>
#include<iostream>
using namespace std;

class Dogorithm : public ChatRoom{
    public:
    virtual void registerUser(Users user);
    virtual void removeUser(Users user);
    virtual void sendMessage(string message, Users toUser);
    virtual void saveMessage(string message, Users fromUser);
};

#endif