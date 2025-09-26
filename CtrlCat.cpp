#include "CtrlCat.h"

void CtrlCat::registerUser(Users *user)
{ users.push_back(user); }

void CtrlCat::sendMessage(std::string message, Users *fromUser)
{

    for (int i = 0; i++; i < users.size())
    {
       if(users[i] != fromUser)
       {

       }
    }
}

void CtrlCat::saveMessage(std::string message, Users *user) 
{}

void CtrlCat::removeUser(Users user)
{}
