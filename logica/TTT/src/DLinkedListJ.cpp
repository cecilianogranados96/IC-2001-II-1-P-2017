/*#include "DLinkedListJ.h"
#include "Jugador.h"
#include <stdexcept>
#include <cstddef>

using namespace std;

DLinkedListJ::DLinkedListJ()
{
    first = new DNodeJ(NULL, NULL);
    last = new DNodeJ(NULL, NULL);
    first->setNext(last);
    last->setPrevious(first);
    curr = first;
    size = 0;
}

DLinkedListJ::~DLinkedListJ()
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

void DLinkedListJ::goToEnd()
{
    curr = last->getPrevious();
}

void DLinkedListJ::goToPos(int pos)
{
    try
    {
        if(pos<0 || pos>size){
            throw runtime_error("La posicion esta fuera de los limites");
        }
        else if (size == 0){
            throw runtime_error("La lista esta vacia");
        }
            int num = 0;
            goToStart();
            curr = curr->getNext();
            while (num < pos)
            {
                num++;
                curr = curr->getNext();
            }
    }
    catch (runtime_error e)
    {
        cout << "Error: " << e.what()<<"\n\n";
    }
}

void DLinkedListJ::next()
{
    if (curr != last->getPrevious())
    {
        curr = curr->getNext();
    }
}

void DLinkedListJ::goToStart()
{
    curr = first;

}

void DLinkedListJ::previous()
{
    if (curr != first)
    {
        curr = curr->getPrevious();
    }
}

int DLinkedListJ::getPos()
{
    int pos = 0;
    DNodeJ* temp = first->getNext();
    while (temp != curr)
    {
        temp = temp->getNext();
        pos ++;
    }
    return pos;
}

int DLinkedListJ::getSize()
{
    return size;
}


DNodeJ* DLinkedListJ::getCurr()
{
    return curr;
}

Jugador* DLinkedListJ::getCurrValue()
{
    return curr->getValue();
}

void DLinkedListJ::append(Jugador* value)
{
    DNodeJ* dnode = new DNodeJ(value,last,last->getPrevious());
    last->getPrevious()->setNext(dnode);
    last->setPrevious(dnode);
    size++;
}

void DLinkedListJ::insert(Jugador* value)
{
    DNodeJ* dnode = new DNodeJ(value, curr->getNext(), curr);
    curr->getNext()->setPrevious(dnode);
    curr->setNext(dnode);
    size++;
}

Jugador* DLinkedListJ::remove()
{
    try
    {
        if((curr == last ) || size == 0)
        {
            throw runtime_error("No element to remove");
        }
        Jugador* valDNodeToDelete = curr->getNext()->getValue();
        DNodeJ* temp = curr->getNext();
        if(curr->getNext()->getNext() == last)
        {
            curr->setNext(last);
            curr->getNext()->setPrevious(curr);
        }
        else
        {
            cout<<"HERE REMOVE";
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

void DLinkedListJ::print()
{
    for(int i = 0; i < size; i++){
        goToPos(i);
        cout<<"\nNombre: "<<getCurrValue()->getNombre()<<" ID: "<<getCurrValue()->getId()<<"\n";
        cout<<"Cartas en mano: ";
        getCurrValue()->getBActual()->print();
    }
}
*/

