#ifndef GENERAL_ITERATOR_H
#define GENERAL_ITERATOR_H

#include"AbstractIterator.h"
#include"AbstractContainer.h"

/***************************************************
This iterator will only point to all task 
***************************************************/

template<class Item>
class GeneralIterator : public AbstractIterator<Item>
{
public:
    GeneralIterator(){};
    GeneralIterator(AbstractContainer<Item> *items);

/***************************************************************************
*@brif : find first index of container 
**************************************************************************/    
    void first();

/*****************************************************************************
*@brif : find next index of container 
*****************************************************************************/ 
    void next();
    
/*****************************************************************************
*@brif : function to check  traverse completely container ?
*****************************************************************************/ 
    bool isDone();

/*****************************************************************************
*@brif : function to return  Item(Task) current.
*****************************************************************************/ 
    Item currentItem();
    
    double numberOfItems();
private:
    AbstractContainer<Item>* myItems;// same as a queue
    long index;
}
template<class Item>
GeneralIterator::GeneralIterator(AbstractContainer<Item> *items)
{
    myItems=items;
    index=0;
}
template<class Item>
void GeneralIterator<Item>::first()
{
    index=0;
}
template<class Item>
void GeneralIterator<Item>::next()
{
    index++;
}
template<class Item>
bool GeneralIterator<Item>::isDone()
{
   bool retVal;
   
   if(index>=myItems->numberOfItems())
       retVal=true;
   else
       retVal=false;
   
   return retVal;
}
template<class Item>
Item GeneralIterator<Item>::currentItem()
{
    if(0==index || myItems->numberOfItems==index)
    {
        first();
    }
    
    return myItems->getItem(index);
}
template<class Item>
double GeneralIterator<Item>::numberOfItems()
{
    return myItems->numberOfItems();
}

#endif GENERAL_ITERATOR_H