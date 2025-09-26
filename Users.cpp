#include "Users.h"
#include<iostream>

Users::Users(const std::string& userName) : name(userName) { 
        chatRooms = new std::vector<ChatRoom*>();
        //commandQueue = new std::vector<Command*>();
}

Users::~Users() {
        delete chatRooms;
        //delete commandQueue;
}

Users::Users(const Users& other) : name(other.name) {
    chatRooms = new std::vector<ChatRoom*>();
    // Copy all chatroom pointers from the other user
    for (size_t i = 0; i < other.chatRooms->size(); i++) {
        chatRooms->push_back((*other.chatRooms)[i]);
    }
}

 bool Users::operator==(const Users& other) const {
        return name == other.name;
}

void Users::send(const std::string& message, ChatRoom* room) {
    // Check if user is in the chat room
    if (!isInChatRoom(room)) {
        std::cout << name << " cannot send message - not in this chat room!" << std::endl;
        return;
    }
    std::cout << name << " sending message to chat room: " << message << std::endl;
    room->sendMessage(message, *this);
}

void Users::receive(const std::string& message, Users fromUser, ChatRoom* room) {
    std::cout << name << " received from " << fromUser.getName() 
              << " in chat room: " << message << std::endl;
}

void Users::joinChatRoom(ChatRoom* room) {
    // Check if user is already in this chat room
    for (size_t i = 0; i < chatRooms->size(); i++) {
        if ((*chatRooms)[i] == room) {
            std::cout << name << " is already in this chat room!" << std::endl;
            return;
        }
    }
    
    chatRooms->push_back(room);
    room->registerUser(*this);
    std::cout << name << " joined chat room!" << std::endl;
}

void Users::leaveChatRoom(ChatRoom* room) {
    for (size_t i = 0; i < chatRooms->size(); i++) {
        if ((*chatRooms)[i] == room) {
            chatRooms->erase(chatRooms->begin() + i);
            room->removeUser(*this);
            std::cout << name << " left chat room!" << std::endl;
            return;
        }
    }
    std::cout << name << " is not in this chat room!" << std::endl;
}

/*void Users::addCommand(Command* command) {
    commandQueue->push_back(command);
}*/

/*void Users::executeAll() {
    for (size_t i = 0; i < commandQueue->size(); i++) {
        (*commandQueue)[i]->execute();
    }
    commandQueue->clear();
}*/

// Assignment operator - ADD THIS
Users& Users::operator=(const Users& other) {
    if (this != &other) {
        name = other.name;
        // Don't copy chatRooms to avoid circular references
        // Keep the existing chatRooms vector
    }
    return *this;
}

bool Users::isInChatRoom(ChatRoom* room) const {
    for (size_t i = 0; i < chatRooms->size(); i++) {
        if ((*chatRooms)[i] == room) {
            return true;
        }
    }
    return false;
}

const std::vector<ChatRoom*>& Users::getChatRooms() const{
    return *chatRooms;
}