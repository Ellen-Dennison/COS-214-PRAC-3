#ifndef ONLINESTATE_H
#define ONLINESTATE_H
#include "State.h"

class OnlineState:public State
{
  
  

  public:
  virtual void send(std::string message, ChatRoom *room);
  //virtual void receive(std::string message, Users *fromUser, ChatRoom *room);
  //virtual void setUser(Users *user) { this->user  = user; }


  
};

#endif 