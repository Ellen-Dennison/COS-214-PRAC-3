#ifndef SENDMESSAGECOMMAND_H
#define SENDMESSAGECOMMAND_H
#include "Command.h"
/** 
* @file SaveMessageCommand.h
* @brief  This is the SaveMessageCommand classs
* @details This file is where the SaveMessageCommand class function is defined  
* @author Ellen Dennsion
* @date  10/09/2025 - 29/09/2025
*   
 */
class SendMessageCommand : public Command {
public:
    SendMessageCommand(ChatRoom* room, const std::string& msg, Users *user);
    virtual ~SendMessageCommand();
    virtual void execute();
};

#endif