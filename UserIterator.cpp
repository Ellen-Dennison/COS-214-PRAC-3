#include <iostream>
#include "UserIterator.h"
#include "Users.h"

UserIterator::UserIterator(std::vector<Users*>* users) 
{ this->users = users; }

Users* UserIterator::first() 
{  
  return users->at(current);
}

Users* UserIterator::next() 
{
   
    if (end())
    {    
        current++;
        Users* result = users->at(current);
        return result; 
    }
    else { return NULL; }
   
}

bool UserIterator::end() 
{ return current < size();}


double UserIterator::size() 
{ return users->size(); }