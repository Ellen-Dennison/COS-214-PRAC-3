#ifndef OFFLINESTATE_H
#define OFFLINESTATE_H
#include "State.h"

/** 
* @file OfflineState.h
* @brief  This is the OfflineState classs
* @details This file is where the OfflineState class function is defined  
* @author Ellen Dennsion
* @date  10/09/2025 - 29/09/2025
*   
 */

class OfflineState:public State
{
 
  public:
  virtual void send(std::string message, ChatRoom *room) override;

};

#endif 