#ifndef ONLINESTATE_H
#define ONLINESTATE_H
#include "State.h"

class OnlineState:public State
{
  
  protected:
  std::vector <ChatRoom*> chatRooms;
  std::string name;
  
  public:
  void send(std::string message, ChatRoom room);
  void receive(std::string message, Users fromUser, ChatRoom room);

  
};

#endif 