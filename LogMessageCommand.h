#ifndef LOGMESSAGECOMMAND_H
#define LOGMESSAGECOMMAND_H
#include "Command.h"

/** 
* @file LogMessageCommand.h
* @brief  This is the LogMessageCommand classs
* @details This file is where the LogMessageCommand class function is defined  
* @author Ellen Dennsion
* @date  10/09/2025 - 29/09/2025
*   
 */

class LogMessageCommand:public Command
{
  public:
  virtual void execute();

};

#endif