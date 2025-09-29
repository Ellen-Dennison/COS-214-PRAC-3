#include "SendMessageCommand.h"
#include "ChatRoom.h"
#include "Users.h"
#include <iostream>

SendMessageCommand::SendMessageCommand(ChatRoom* room, const std::string& msg, Users *user) 
    : Command(room, msg, user) {
    // Constructor calls base class constructor to initialize members
}

SendMessageCommand::~SendMessageCommand() {
    // No additional cleanup needed
}

void SendMessageCommand::execute() {
    std::cout << "Executing SendMessageCommand..." << std::endl;
    // Call the chatRoom's sendMessage method to deliver message to all users
    chatRoom->sendMessage(message, fromUser);
}