#ifndef CTRLCAT_H
#define CTRLCAT_H

#include "ChatRoom.h"
#include "Users.h"
#include <string>
#include <vector>

class CtrlCat : public ChatRoom
{
    private:
    std::vector <Users*> users;
    std::vector <std::string*> chatHistory;

    public:
    virtual void registerUser(Users *user);
    virtual void sendMessage(std::string message, Users *fromUser);
    virtual void saveMessage(std::string message, Users *user) ;
    virtual void removeUser(Users user);

};
#endif