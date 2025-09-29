#include "Command.h"
#include "ChatRoom.h"
#include "Users.h"
Command::Command(ChatRoom *room, string message, Users* user)
         : chatRoom(room), message(message), fromUser(user){}

Command::~Command(){}