#include "ChatRoom.h"
using namespace std;
#include<string>


/** 
 * @brief ChatRoom constructor
 * @param - 
 * @details This function initializes the ChatRoom attributes 
 * @return -
 */
ChatRoom::ChatRoom(){
    users = new std::vector<Users>();
    chatHistory = new std::vector<string>();
}

/** 
 * @brief ChatRoom destructor
 * @param - 
 * @details This function deletes the memoery that was allocated to ChatRooms' attributes 
 * @return -
 */
ChatRoom::~ChatRoom(){
    delete users;
    delete chatHistory;
}


/** 
 * @brief function to get the user vector
 * @param - 
 * @details This function returns a pointer to the user vector 
 * @return a pointer to the users vector 
 */
const std::vector<Users>& ChatRoom::getUsers(){
    return *users;
}


/** 
 * @brief function to get the chatHistory vector
 * @param - 
 * @details This function returns a pointer to the chatHistory vector 
 * @return a pointer to the chatHistory vector 
 */
const std::vector<std::string>& ChatRoom::getChatHistory(){
    return *chatHistory;
}


/** 
 * @brief function to get the user vector
 * @param - 
 * @details This function returns a pointer to the user vector 
 * @return a pointer to the users vector 
 */
size_t ChatRoom::getUserCount(){
    return users->size();
}

size_t ChatRoom::getMessageCount(){ 
    return chatHistory->size();
}

bool ChatRoom::hasUser(Users user){
    for (size_t i = 0; i < users->size(); i++) {
        if ((*users)[i] == user) {
            return true;
        }
    }
    return false;
}
