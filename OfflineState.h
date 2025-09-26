#ifndef OFFLINESTATE_H
#define OFFLINESTATE_H
#include "State.h"

class OfflineState:public State
{
  protected:
  std::vector <ChatRoom*> chatRooms;
  std::string name;
  
  public:
  virtual void send(std::string message, ChatRoom *room);
  virtual void receive(std::string message, Users *fromUser, ChatRoom *room);


};

#endif 