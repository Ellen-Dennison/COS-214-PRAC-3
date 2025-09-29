#ifndef ITERATOR_H
#define ITERATOR_H

class Iterator
{
  public:
  virtual void first() = 0;
  virtual void next() = 0;
  virtual bool end() = 0;
  virtual double size() = 0;
};
#endif