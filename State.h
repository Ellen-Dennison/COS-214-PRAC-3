#ifndef STATE_H
#define STATE_H

#include "Users.h"
#include "ChatRoom.h"

#include <string>
#include <iostream>
#include <vector>

class State
{
  protected:
  std::vector <ChatRoom*> chatRooms;
  std::string name;
  
  public:
  void send(std::string message, ChatRoom room);
  void receive(std::string message, Users fromUser, ChatRoom room);
    
};

#endif STATE_H