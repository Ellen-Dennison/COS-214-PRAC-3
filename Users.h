#ifndef USERS_H
#define USERS_H
//#include "Command.h"
#include "ChatRoom.h"
#include "State.h"
#include<string>
#include<vector>

class ChatRoom;
class State;
//class Command;

class Users
{
        protected:
              std::vector<ChatRoom*>* chatRooms; //pointer to vector of chatRoom pointers
              std::string name;
              State *newState;
              std::vector<Command*>* commandQueue;//pointer to vector of command pointers
    public:
             Users(const std::string& userName);
             Users(const Users& other);
             virtual ~Users();
             const std::string& getName() const { return name; }
             
             // Make parameters const to match your implementation
             void send(const std::string& message, ChatRoom* room);
             void receive(const std::string& message, Users fromUser, ChatRoom* room);
             void addCommand(Command* command);
             void executeAll();
             void joinChatRoom(ChatRoom*);
             void leaveChatRoom(ChatRoom*);
             bool operator==(const Users& other) const;
             const std::vector<ChatRoom*>& getChatRooms() const;
             bool isInChatRoom(ChatRoom* room) const;
             Users& operator=(const Users& other);

             void setState(State *setState);
};
#endif