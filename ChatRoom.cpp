#include "ChatRoom.h"
#include "Users.h"  // Add this include
using namespace std;
#include<string>


/** 
 * @brief ChatRoom constructor
 * @param - 
 * @details This function initializes the ChatRoom attributes 
 * @return -
 */
ChatRoom::ChatRoom(){
    users = new std::vector<Users*>();      // Changed to Users*
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
const std::vector<Users*>& ChatRoom::getUsers(){  // Changed return type
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
 * @brief function to get the users vector size 
 * @param - 
 * @details This function returns the size of the users vector 
 * @return size of the users vector 
 */
size_t ChatRoom::getUserCount(){
    return users->size();
}

/** 
 * @brief function to get the chatHistory vector size
 * @param - 
 * @details This function returns the size of the chatHistory vector 
 * @return size of the chatHistory vector  
 */
size_t ChatRoom::getMessageCount(){ 
    return chatHistory->size();
}

/** 
 * @brief function to get check if a user is in the users vector
 * @param a pointer to a user object  
 * @details This function checks if a user is within the users vector and returns true if the user is found 
 * @return boolean value  
 */
bool ChatRoom::hasUser(Users* user){        // Changed parameter
    for (size_t i = 0; i < users->size(); i++) {
        if ((*users)[i] == user) {                // Compare pointers
            return true;
        }
    }
    return false;
}