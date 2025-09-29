#ifndef STATE_H
#define STATE_H

#include "Users.h"
#include "ChatRoom.h"

class Users;
class ChatRoom;

#include <string>
#include <iostream>
#include <vector>

/** 
* @file State.h
* @brief  This is the State classs
* @details This file is where the State class functions are defined  
* @author Ellen Dennsion
* @date  10/09/2025 - 29/09/2025
*   
 */

class State
{
  protected:
  std::vector <ChatRoom*> chatRooms;
  std::string name;
  Users* user;


  public:
  virtual void send(std::string message, ChatRoom *room) = 0;
  virtual void setUser(Users *user) { this->user  = user; }

    
};

#endif 