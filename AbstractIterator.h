#ifndef ABSTRACT_ITERATOR_H
#define ABSTRACT_ITERATOR_H

class AbstractIterator
{
public:
    virtual void First()=0;
    virtual void Next()=0;
    virtual bool IsDone()=0;
    virtual Item CurrentItem()=0;
    virtual double NumberOfItem()=0;
protected:
    AbstractIterator(){};
    ~AbstractIterator(){};
}

#endif/*ABSTRACT_ITERATOR_H*/