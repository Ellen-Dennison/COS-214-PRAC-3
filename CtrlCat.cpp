#include "CtrlCat.h"

void CtrlCat::registerUser(Users user)
{
    users->push_back(user); //store users object by value
    std::cout<<user.getName()<<" joined by CtrlCat chat room!"<<std::endl;
}

void CtrlCat::removeUser(Users user) 
{
    for (size_t i = 0; i < users->size(); i++) {
        if ((*users)[i] == user) {
            users->erase(users->begin() + i);
            std::cout << user.getName() << " left CtrlCat chat room!" << std::endl;
            return;
        }
    }
}

/*************************************************************************************************/
//Messages have not been given to user 

void CtrlCat::sendMessage(string message, Users fromUser)
{
    if(hasUser(fromUser))
    {
        cout<< "New message from " << fromUser.getName()<<endl;
        for (int i = 0; i < users->size();i++)
        {
            if (fromUser == (*users)[i])
            {}
            else 
            { (*users)[i].receive(message,fromUser,this); }
        }
        chatHistory->push_back(message);
    }
    else
    { cout<<"Cannot send a message to this chatRoom!\n"; }

}

void CtrlCat::saveMessage(string message, Users fromUser)
{
    if(hasUser(fromUser))
    {
        cout<<fromUser.getName()<<" Draft saved!\n";
        chatHistory->push_back("New message from " +fromUser.getName()+" "+ message);
    }
    else
    { cout<<"Cannot save this message!\n"; }
}
