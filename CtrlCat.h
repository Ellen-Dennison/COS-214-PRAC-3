#ifndef CTRLCAT_H
#define CTRLCAT_H
#include "ChatRoom.h"

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