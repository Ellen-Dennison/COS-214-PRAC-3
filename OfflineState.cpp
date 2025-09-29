#include "OfflineState.h"
#include <iostream>
#include <vector>

void OfflineState::send(std::string message,ChatRoom *room)
{
    if (!user->isInChatRoom(room)) 
    {
        std::cout << name << " cannot send message - not in this chat room!\n" << std::endl;
        return;
    }
    std::cout << name << "saving message. Message will be sent when user is online\n" << message << std::endl;
    room->saveMessage(message, user);    
}

