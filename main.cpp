#include "ChatRoom.h"
#include "CtrlCat.h"
#include "Dogorithm.h"
#include "Users.h"
#include "Name1.h"
#include "Name2.h"
#include "Name3.h"
#include "Command.h"
#include "SendMessageCommand.h"
#include "SaveMessageCommand.h"
#include "OfflineState.h"
#include "OnlineState.h"
#include<string>
#include<iostream>
using namespace std;



int main(){
    cout << "========== TESTING MEDIATOR PATTERN ==========" << endl;
    
    ChatRoom *catRoom = new CtrlCat();
    Users *user1 = new Name1("Jackie Brown");
    Users *user2 = new Name2("Maxwell Hilton");
    user1->joinChatRoom(catRoom);
    user2->joinChatRoom(catRoom);

    ChatRoom *dogRoom = new Dogorithm();
    Users *user3 = new Name1("Harry Styles");
    Users *user4 = new Name2("James Carter");
    Users *user5 = new Name3("Halle Berry");
    user3->joinChatRoom(dogRoom);
    user4->joinChatRoom(dogRoom);
    user5->joinChatRoom(dogRoom);
    user1->joinChatRoom(dogRoom);

    cout << "\n========== TESTING COMMAND PATTERN ==========" << endl;
    
    // Test 1: Test send() which should create and execute commands
    cout << "\n--- Test 1: User2 sends message using Command pattern ---" << endl;
    user2->send("Hello everyone, I love cats!", catRoom);
    
    cout << "\n--- Test 2: User3 sends message to dogRoom ---" << endl;
    user3->send("Hey guys, I love dogs!", dogRoom);
    
    cout << "\n--- Test 3: User1 sends to multiple rooms (is in both) ---" << endl;
    user1->send("I love both cats and dogs!", dogRoom);
    
    // Test 4: Test addCommand and executeAll directly
    cout << "\n--- Test 4: Manually creating and executing commands ---" << endl;
    // In main.cpp, update Test 4:
    Command* cmd1 = new SendMessageCommand(catRoom, "Manual send test", user2);  // Pass pointer
    Command* cmd2 = new SaveMessageCommand(catRoom, "Manual save test", user2);  // Pass pointer
    
    user2->addCommand(cmd1);
    user2->addCommand(cmd2);
    
    cout << "Executing commands from queue..." << endl;
    user2->executeAll();
    
    // Test 5: Check chat history to verify messages were saved
    cout << "\n--- Test 5: Verifying messages in chat history ---" << endl;
    const std::vector<string>& catHistory = catRoom->getChatHistory();
    const std::vector<string>& dogHistory = dogRoom->getChatHistory();
    
    cout << "\nCatRoom chat history (" << catHistory.size() << " messages):" << endl;
    for (size_t i = 0; i < catHistory.size(); i++){
        cout << "  [" << i << "] " << catHistory[i] << endl;
    }
    
    cout << "\nDogRoom chat history (" << dogHistory.size() << " messages):" << endl;
    for (size_t i = 0; i < dogHistory.size(); i++){
        cout << "  [" << i << "] " << dogHistory[i] << endl;
    }
    
    // Test 6: Test that user NOT in room cannot send
    cout << "\n--- Test 6: User tries to send to room they're not in ---" << endl;
    user1->leaveChatRoom(catRoom);
    user1->send("Can I still send here?", catRoom);  // Should fail
    
    // Test 7: Verify message count
    cout << "\n--- Test 7: Message counts ---" << endl;
    cout << "CtrlCat has " << catRoom->getMessageCount() << " messages" << endl;
    cout << "Dogorithm has " << dogRoom->getMessageCount() << " messages" << endl;
    
    // Test 8: Multiple commands in queue
    cout << "\n--- Test 8: Multiple commands queued and executed together ---" << endl;
    user4->addCommand(new SendMessageCommand(dogRoom, "First message", user4));   // Pass pointer
    user4->addCommand(new SaveMessageCommand(dogRoom, "First message", user4));   // Pass pointer
    user4->addCommand(new SendMessageCommand(dogRoom, "Second message", user4));  // Pass pointer
    user4->addCommand(new SaveMessageCommand(dogRoom, "Second message", user4));  // Pass pointer
    
    cout << "Executing batch of 4 commands..." << endl;
    user4->executeAll();
    
    cout << "\nFinal Dogorithm message count: " << dogRoom->getMessageCount() << endl;
    
    // Test 9: Test user functionality
    cout << "\n========== TESTING USER CLASS ==========" << endl;
    cout << "User2's name: " << user2->getName() << endl;
    
    if(user5->isInChatRoom(dogRoom)){
        cout << "User5 is in dogRoom: YES" << endl;
    }
    
    const std::vector<ChatRoom*>& user2rooms = user2->getChatRooms();
    cout << "User2 is in " << user2rooms.size() << " room(s)" << endl;
    
    const std::vector<ChatRoom*>& user1rooms = user1->getChatRooms();
    cout << "User1 is in " << user1rooms.size() << " room(s)" << endl;
    
    // Test 10: Test getUserCount
    cout << "\n--- Test 10: Room user counts ---" << endl;
    cout << "CtrlCat has " << catRoom->getUserCount() << " users" << endl;
    cout << "Dogorithm has " << dogRoom->getUserCount() << " users" << endl;
    
    // Cleanup
    cout << "\n========== CLEANUP ==========" << endl;
    delete catRoom;
    delete dogRoom;
    delete user1;
    delete user2;
    delete user3;
    delete user4;
    delete user5;
    
    cout << "\nAll tests completed successfully!" << endl;
    cout<<"-------------------------------------------------------STATE TEST------------------------------------------------------------------------------------\n";
    
    Users *u1 =  new Name1("Hope");
    Users *u2 =  new Name1("Ellen");
    ChatRoom* c1 = new CtrlCat;
    State *s1 = new OfflineState;
    
    u1->joinChatRoom(c1);
    u2->joinChatRoom(c1);
    //u1->send("Hello everyone", c1);
     

    //STATE TEST 
    std::cout << "\n==User is in offline mode==\n";
    s1->setUser(u2);
    s1->send("Hello Me",c1);
    
    //USERS OLD MESSAGES SENT FIRST
    delete s1;
    s1 = new OnlineState;
    std::cout << "\n==User is in onfline mode==\n";
    s1->setUser(u2);
    s1->send("Will my message be sent",c1);
    s1->send("Will you get this second message",c1);
    delete u1, u2, c1, s1;
    
    return 0;
}