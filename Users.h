#ifndef USERS_H
#define USERS_H


#include "State.h"
#include <string>
#include <iostream>

class Users
{
    private:
    State *newState;

    public:
    void setState(State *setState);

};
#endif