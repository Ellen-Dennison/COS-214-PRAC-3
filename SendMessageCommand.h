#ifndef SENDMESSAGECOMMAND_H
#define SENDMESSAGECOMMAND_H
#include "Command.h"

class SendMessageCommand : public Command {
public:
    SendMessageCommand(ChatRoom* room, const std::string& msg, Users *user);
    virtual ~SendMessageCommand();
    virtual void execute();
};

#endif