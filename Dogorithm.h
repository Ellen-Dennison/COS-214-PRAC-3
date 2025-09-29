#ifndef DOGORITHM_H
#define DOGORITHM_H
#include "ChatRoom.h"
#include<string>
#include<iostream>
using namespace std;

/** 
* @file Dogorithm.h
* @brief  This is the Dogorithm classs
* @details This file is where the Dogorithm class functions are defined  
* @author Nomzi Phosa
* @date  10/09/2025 - 29/09/2025
*   
 */

class Dogorithm : public ChatRoom{
    public:
    virtual void registerUser(Users user);
    virtual void removeUser(Users user);
    virtual void sendMessage(string message, Users toUser);
    virtual void saveMessage(string message, Users fromUser);
};

#endif