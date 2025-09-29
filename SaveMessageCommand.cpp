#include "SaveMessageCommand.h"
#include<iostream>
#include "ChatRoom.h"

SaveMessageCommand::SaveMessageCommand(ChatRoom *room, string message, Users *user)
                   : Command(room,message,user){}


void SaveMessageCommand::execute(){
    cout << "Executing SaveMessageCommand...\n";
    chatRoom->saveMessage(message, fromUser);
}

SaveMessageCommand::~SaveMessageCommand(){}


