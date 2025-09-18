#ifndef SENDMESSAGECOMMAND
#define SENDMESSAGECOMMAND
#include "Command.h"

class SendMessageCommand:public Command
{ 
  public:
  virtual void execute();

};
#endif