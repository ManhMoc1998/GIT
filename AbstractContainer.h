#ifndef ABSTRACT_CONTAINER_H
#define ABSTRACT_CONTAINER_H

#include"AbstractIterator.h"

template<class Item>
class AbstractContainer
{
public :
    virtual AbstractContainer<Item> *createIterator()=0;
    virtual void addItem(Item a)=0;
    virtual void remove(Item a)=0;
    virtual int numberOfItems()=0;
    virtual Item getItem(int index)=0;
};
#endif/*ABSTRACT_CONTAINER_H*/