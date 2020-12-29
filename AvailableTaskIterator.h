#ifndef AVAILABLE_TASK_ITERATOR_H
#ifndef AVAILABLE_TASK_ITERATOR_H

#include"AbstractIterator.h"
#include"AbstractContainer.h"

/***************************************************
This iterator will only point to task available for
execution.
That tasks with the states : Ready , Running ,Waitting
***************************************************/

template<class Item>
class AvailableTaskIterator : public AbstractIterator<Item>
{
public:
    AvailableTaskIterator(){};
    AvailableTaskIterator(AbstractContainer<Item> *items);

/***************************************************************************
*@brif : find first index of container that task is available for execute
**************************************************************************/    
    void first();

/*****************************************************************************
*@brif : find next index of container that task is available task for execute
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
AvailableTaskIterator::AvailableTaskIterator(AbstractContainer<Item> *items)
{
    myItems=items;
    index=0;
}
template<class Item>
void AvailableTaskIterator<Item>::first()
{
    index=0;
    while(!isDone())
    {
        state_task_t tempState=myItems->getItem(index)->getState();
        if(tempState==READY ||tempState== RUNNING || tempState==WAITING)
        {
            return;
        }
        index++;
    }
}
template<class Item>
void AvailableTaskIterator<Item>::next()
{
    index++;
    while(!isDone())
    {
        state_task_t tempState=myItems->getItem(index)->getState();
        if(tempState==READY ||tempState== RUNNING || tempState==WAITING)
        {
            return;
        }
        index++;
    }
}
template<class Item>
bool AvailableTaskIterator<Item>::isDone()
{
   bool retVal;
   
   if(index>=myItems->numberOfItems())
       retVal=true;
   else
       retVal=false;
   
   return retVal;
}
template<class Item>
Item AvailableTaskIterator<Item>::currentItem()
{
    if(0==index || myItems->numberOfItems==index)
    {
        first();
    }
    
    return myItems->getItem(index);
}
template<class Item>
double AvailableTaskIterator<Item>::numberOfItems()
{
    return myItems->numberOfItems();
}
#endif/*AVAILABLE_TASK_ITERATOR_H*/