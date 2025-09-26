#include "ChatRoom.h"
#include "CtrlCat.h"
#include "Dogorithm.h"
#include "Users.h"
#include "Name1.h"
#include "Name2.h"
#include "Name3.h"
#include<string>
#include<iostream>
using namespace std;

int main(){
    ChatRoom *catRoom = new CtrlCat();
    Users *user1 = new Name1("Jackie Brown");
    Users *user2 = new Name2("Maxwell Hilton");
    user1->joinChatRoom(catRoom);
    user2->joinChatRoom(catRoom);
    catRoom->registerUser(*user1);
    catRoom->registerUser(*user2);
    

    ChatRoom *dogRoom = new Dogorithm();
    Users *user3 = new Name1("Harry Styles");
    Users *user4 = new Name2("James Carter");
    Users *user5 = new Name3("Halle Berry");
    user3->joinChatRoom(dogRoom);
    user4->joinChatRoom(dogRoom);
    user5->joinChatRoom(dogRoom);
    user1->joinChatRoom(dogRoom);
    dogRoom->registerUser(*user3);
    dogRoom->registerUser(*user4);
    dogRoom->registerUser(*user5);
    dogRoom->registerUser(*user1);

    //removing the user
    catRoom->removeUser(*user1);
    user1->leaveChatRoom(catRoom);

    std::cout<<"----------------------------------------------------------------------------------------------------------------------------\n";

    //getting the users from chatRoom
    const std::vector<Users>& catUsers = catRoom->getUsers();
    const std::vector<Users>& dogUsers = dogRoom->getUsers();

    std::cout<<"Current catRoom users:\n";
    for (size_t i = 0; i < catUsers.size(); i++){
        std::cout<<catUsers[i].getName()<<std::endl;
    }
    

    std::cout<<"Current dogRoom users:\n";
    for (size_t i = 0; i < dogUsers.size(); i++){
        std::cout<<dogUsers[i].getName()<<std::endl;
    }
    std::cout<<"-----------------------------------------------------------------------------------------------------------------------------\n";

    //getting chats from chatRooms
    const std::vector<string>& catHistory = catRoom->getChatHistory();
    const std::vector<string>& dogHistory = dogRoom->getChatHistory();

     std::cout<<"Current catRoom chatHistory:\n";
    for (size_t i = 0; i < catHistory.size(); i++){
        std::cout<<catHistory[i]<<std::endl;
    }
    std::cout<<"-----------------------------------------------------------------------------------------------------------------------------\n";

    std::cout<<"Current dogRoom chatHistory:\n";
    for (size_t i = 0; i < dogHistory.size(); i++){
        std::cout<<dogHistory[i]<<std::endl;
    }

    //getting the number of users
    std::cout<<"CtrlCat has "<<catRoom->getUserCount()<<" users"<<endl;
    std::cout<<"Dogorithm has "<<dogRoom->getUserCount()<<" users"<<endl;
    cout<<"----------------------------------------------------------------------------------------------------------------------------------------\n";
    //getting the number of messages
    cout<<"CtrlCat has "<<catRoom->getMessageCount()<<" messages"<<endl;
    cout<<"Dogorithm has "<<dogRoom->getMessageCount()<<" messages"<<endl;

    //trying to find a user
    if(catRoom->hasUser(*user1)){
        cout<<"Cat Room has Jackie Brown"<<endl;
    }
    else{
        cout<<"Jackie Brown is not here!\n";
    }
   
    if (dogRoom->hasUser(*user5)){
        cout<<"Halle is here\n";
    }
    else{
        cout<<"Halle is not here\n";
    }

    //Testing the User Class
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"TESTING THE USERS CLASS\n";

    const std::string& user2Name = user2->getName();
    cout<<"User2's name is: "<<user2Name<<endl;

    //testing the send function
    user1->send("Hey everyone, I just joined the chat room and I love cats!", catRoom);
    user2->send("Hey everyone, I just joined the chat room and I love cats!", catRoom);
    user3->send("Hey guys, I love dogs!", dogRoom);
    user4->send("Hey guys, i love dogs too", dogRoom);
    user5->receive("Hey guys, i love dogs too",*user4,dogRoom);

    //checking if user is in chatRoom
    if(user5->isInChatRoom(dogRoom)){
        cout<<"User is in dog room"<<endl;
    }
    else{
        cout<<"not there\n";
    }

    //testing getChatRooms
    const std::vector<ChatRoom*>& user2rooms = user2->getChatRooms();
    cout << "   User2's rooms: " << user2rooms.size() << endl;
    
    delete catRoom;
    delete dogRoom;
    
    // Now delete users
    delete user1;
    delete user2;
    delete user3;
    delete user4;
    delete user5;
}