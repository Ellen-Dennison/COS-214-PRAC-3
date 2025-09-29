#ifndef LOGMESSAGECOMMAND_H
#define LOGMESSAGECOMMAND_H
#include "Command.h"


class LogMessageCommand:public Command
{
  public:
  virtual void execute();

};

#endif