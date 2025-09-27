#ifndef CTRLCAT_H
#define CTRLCAT_H
#include "ChatRoom.h"
#include<iostream>
#include<string>
using namespace std;

class CtrlCat : public ChatRoom{
    public:
    virtual void registerUser(Users user);
    virtual void removeUser(Users user);
    virtual void sendMessage(string message, Users fromUser);
    virtual void saveMessage(string message, Users fromUser);
};
#endif