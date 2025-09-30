#ifndef USERITERATOR_H
#define USERITERATOR_H
#include "Iterator.h"
#include "Users.h"

class UserIterator:public Iterator
{  
  private:
  std::vector<Users*>* users;
  int current = 0;

  public:
  UserIterator(std::vector<Users*>* users);
  virtual Users* first() override;
  virtual Users* next() override;
  virtual bool end() override;
  virtual double size() override;
};

#endif