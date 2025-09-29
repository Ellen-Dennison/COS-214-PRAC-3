#ifndef COMMAND_H
#define COMMAND_H
#include<string>
using namespace std;

class ChatRoom;
class Users;
class Command{
    protected:
                ChatRoom *chatRoom;
                string message;
                Users* fromUser;
    public:
                virtual void execute() = 0;
                Command(ChatRoom* room, string message, Users *user);
                virtual ~Command();
};
#endif