#ifndef STATE_H
#define STATE_H

//#include "Users.h"
//#include "ChatRoom.h"

class Users;
class ChatRoom;

#include <string>
#include <iostream>
#include <vector>

class State
{
  
  /* 
  protected:
  std::vector <ChatRoom*> chatRooms;
  std::string name; 
  */

  public:
  virtual void send(std::string message, ChatRoom *room) = 0;
  virtual void receive(std::string message, Users *fromUser, ChatRoom *room) = 0;
    
};

#endif 