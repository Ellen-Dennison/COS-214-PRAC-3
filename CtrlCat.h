#ifndef CTRLCAT_H
#define CTRLCAT_H
#include "ChatRoom.h"
#include<iostream>
#include<string>
using namespace std;

/** 
* @file CtrlCat.h
* @brief  This is the CtrlCat classs
* @details This file is where the CtrlCat class functions are defined  
* @author Nomzi Phosa
* @date  10/09/2025 - 29/09/2025
*   
 */

class CtrlCat : public ChatRoom{
    public:
    virtual void registerUser(Users user);
    virtual void removeUser(Users user);
    virtual void sendMessage(string message, Users fromUser);
    virtual void saveMessage(string message, Users fromUser);
};
#endif