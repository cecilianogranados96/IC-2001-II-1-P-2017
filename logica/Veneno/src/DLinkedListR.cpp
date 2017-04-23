#include "DLinkedListR.h"
#include "Ronda.h"
#include <stdexcept>
#include <cstddef>

using namespace std;

DLinkedListR::DLinkedListR()
{
    first = new DNodeR(NULL, NULL);
    last = new DNodeR(NULL, NULL);
    first->setNext(last);
    last->setPrevious(first);
    curr = first;
    size = 0;
}

DLinkedListR::~DLinkedListR()
{
    while (first !=NULL)
    {
        curr = first;
        first = first->getNext();
        delete curr;
    }
    size = 0;
    delete first;
    delete last;
}

void DLinkedListR::goToEnd()
{
    curr = last->getPrevious();
}

void DLinkedListR::goToPos(int pos)
{
    int num = 0;
    goToStart();
    curr = curr->getNext();
    while (num < pos)
    {
        num++;
        curr = curr->getNext();
    }
}

void DLinkedListR::next()
{
    if (curr != last->getPrevious())
    {
        curr = curr->getNext();
    }
}

void DLinkedListR::goToStart()
{
    curr = first;

}

void DLinkedListR::previous()
{
    if (curr != first)
    {
        curr = curr->getPrevious();
    }
}

int DLinkedListR::getPos()
{
    int pos = 0;
    DNodeR* temp = first->getNext();
    while (temp != curr)
    {
        temp = temp->getNext();
        pos ++;
    }
    return pos;
}

int DLinkedListR::getSize()
{
    return size;
}


DNodeR* DLinkedListR::getCurr()
{
    return curr;
}

Ronda* DLinkedListR::getCurrValue()
{
    return curr->getValue();
}

void DLinkedListR::append (Ronda* value)
{
    DNodeR* dnode = new DNodeR(value,last,last->getPrevious());
    last->getPrevious()->setNext(dnode);
    last->setPrevious(dnode);
    size++;
}

void DLinkedListR::insert(Ronda* value)
{
    DNodeR* dnode = new DNodeR(value, curr->getNext(), curr);
    curr->getNext()->setPrevious(dnode);
    curr->setNext(dnode);
    size++;
}

Ronda* DLinkedListR::remove()
{
    try
    {
        if((curr == last ) || size == 0)
        {
            throw runtime_error("No element to remove");
        }
        Ronda* valDNodeToDelete = curr->getNext()->getValue();
        DNodeR* temp = curr->getNext();
        if(curr->getNext()->getNext() == last)
        {
            curr->setNext(last);
            curr->getNext()->setPrevious(curr);
        }
        else
        {
            curr->setNext(curr->getNext()->getNext());
            curr = curr->getNext();
            curr->getNext()->setPrevious(curr);
        }


        //delete temp;
        size--;
        return valDNodeToDelete;
    }
    catch (runtime_error e)
    {
        cout << "Error: " << e.what()<<"\n\n";
    }
}

void DLinkedListR::print()
{
    for(int i = 0; i < size; i++){
        goToPos(i);
    }
}
