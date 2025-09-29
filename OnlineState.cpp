#include "OnlineState.h"
#include <iostream>
#include <vector>

void OnlineState::send(std::string message, ChatRoom *room)
{
    if (!user->isInChatRoom(room)) 
    {
        std::cout << name << " cannot send message - not in this chat room!" << std::endl;
        return;
    }

    std::vector <string> c1 = room->getChatHistory();
    for (int i = 0; i < c1.size(); i++)
    {
       if (user->getName().compare(c1[i]))
       {
         std::cout << "sending your drafts\n";
         room->sendMessage(c1[i], user);
       }
       if (message.compare(c1[i]) != 0) 
       {
         std::cout << name << " sending message to chat room: " << message << std::endl;
         room->sendMessage(message, user);
       }
    }
    
    

}

