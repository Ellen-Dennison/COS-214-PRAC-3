#ifndef ITERATOR_H
#define ITERATOR_H
#include "Users.h"
class Users;

class Iterator
{  
  private:
  std::vector<Users*>* users;

  public:
  virtual Users* first() = 0;
  virtual Users* next() = 0;
  virtual bool end() = 0;
  virtual double size() = 0;
};
#endif