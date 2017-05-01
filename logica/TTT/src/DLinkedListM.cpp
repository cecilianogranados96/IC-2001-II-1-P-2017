/*#include "DLinkedListM.h"
#include "Movimiento.h"
#include <stdexcept>
#include <cstddef>

using namespace std;

DLinkedListM::DLinkedListM()
{
    first = new DNodeM(NULL, NULL);
    last = new DNodeM(NULL, NULL);
    first->setNext(last);
    last->setPrevious(first);
    curr = first;
    size = 0;
}

DLinkedListM::~DLinkedListM()
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

void DLinkedListM::goToEnd()
{
    curr = last->getPrevious();
}

void DLinkedListM::goToPos(int pos)
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

void DLinkedListM::next()
{
    if (curr != last->getPrevious())
    {
        curr = curr->getNext();
    }
}

void DLinkedListM::goToStart()
{
    curr = first;

}

void DLinkedListM::previous()
{
    if (curr != first)
    {
        curr = curr->getPrevious();
    }
}

int DLinkedListM::getPos()
{
    int pos = 0;
    DNodeM* temp = first->getNext();
    while (temp != curr)
    {
        temp = temp->getNext();
        pos ++;
    }
    return pos;
}

int DLinkedListM::getSize()
{
    return size;
}


DNodeM* DLinkedListM::getCurr()
{
    return curr;
}

Movimiento* DLinkedListM::getCurrValue()
{
    return curr->getValue();
}

void DLinkedListM::append (Movimiento* value)
{
    DNodeM* dnode = new DNodeM(value,last,last->getPrevious());
    last->getPrevious()->setNext(dnode);
    last->setPrevious(dnode);
    size++;
}

void DLinkedListM::insert(Movimiento* value)
{
    DNodeM* dnode = new DNodeM(value, curr->getNext(), curr);
    curr->getNext()->setPrevious(dnode);
    curr->setNext(dnode);
    size++;
}

Movimiento* DLinkedListM::remove()
{
    try
    {
        if((curr == last ) || size == 0 || curr == NULL)
        {
            throw runtime_error("No element to remove");
        }
        Movimiento* valDNodeToDelete = curr->getNext()->getValue();
        DNodeM* temp = curr->getNext();
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

void DLinkedListM::print()
{
    for(int i = 0; i < size; i++){
        goToPos(i);
        cout<<"\nMovimientos:\nJugador: ";
        getCurrValue()->getJugador()->print();
        cout<<"Estado de undo: "<<getCurrValue()->getUndo()<<"\n";
        cout<<"Naipe en juego:";
        getCurrValue()->getNaipe()->print();
        cout<<"Caldero: ";
        getCurrValue()->getCaldero()->getBaraja()->print();
        cout<<"Baraja de comidas: ";
        getCurrValue()->getBComidas()->print();
        cout<<"Baraja de venenos: ";
        getCurrValue()->getBVenenos()->print();
    }
}*/
