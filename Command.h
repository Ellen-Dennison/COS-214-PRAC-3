#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <vector>
#include "ChatRoom.h"
#include "Users.h"

/** 
* @file Command.h
* @brief  This is the Command classs
* @details This file is where the Command class functions are defined  
* @author Ellen Dennsion
* @date  10/09/2025 - 29/09/2025
*   
 */

class Command
{
    protected:
    ChatRoom *room;//pointer to chatRoom object
    std::string message;//string containing user message 
    Users fromUser;//User attribute that will be used to access user functions in the command class
    
    public:
    virtual void execute() = 0;
    Command(ChatRoom *room, std::string message, Users fromUser);
};

#endif