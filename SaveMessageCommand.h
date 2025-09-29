#ifndef SAVEMESSAGECOMMAND_H
#define SAVEMESSAGECOMMAND_H
#include "Command.h"

class SaveMessageCommand : public Command{
    public:
    SaveMessageCommand(ChatRoom *room, string message, Users* user);
    virtual ~SaveMessageCommand();
    virtual void execute();
};
#endif