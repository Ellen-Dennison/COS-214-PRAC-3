#ifndef CTRLCAT_H
#define CTRLCAT_H
#include "ChatRoom.h"

/** 
* @file CtrlCat.h
* @brief  This is the CtrlCat classs
* @details This file is where the CtrlCat class functions are defined  
* @author Nomzi Phosa
* @date  10/09/2025 - 29/09/2025
*   
 */

class CtrlCat : public ChatRoom {
public:
    CtrlCat();
    virtual ~CtrlCat();
    
    virtual void registerUser(Users* user);      // Changed to Users*
    virtual void removeUser(Users* user);        // Changed to Users*
    virtual void sendMessage(string message, Users* fromUser);    // Changed to Users*
    virtual void saveMessage(string message, Users* fromUser);    // Changed to Users*
};

#endif