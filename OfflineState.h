#ifndef OFFLINESTATE_H
#define OFFLINESTATE_H
#include "State.h"

class OfflineState:public State
{
 
  public:
  virtual void send(std::string message, ChatRoom *room) override;
  //virtual void receive(std::string message, Users *fromUser, ChatRoom *room);
  //virtual void setUser(Users *user) { this->user  = user; }


};

#endif 