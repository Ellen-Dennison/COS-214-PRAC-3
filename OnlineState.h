#ifndef ONLINESTATE_H
#define ONLINESTATE_H
#include "State.h"

/** 
* @file OnlineState.h
* @brief  This is the OnlineState classs
* @details This file is where the OnlineState class function is defined  
* @author Ellen Dennsion
* @date  10/09/2025 - 29/09/2025
*   
 */


class OnlineState:public State
{

  public:
  virtual void send(std::string message, ChatRoom *room);
  
};

#endif 